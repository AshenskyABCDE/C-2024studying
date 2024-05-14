#include <thread>
#include <iostream>
#include <string>
#include <mutex>
using namespace std;

static mutex mux;
void TestThread() {
    // 锁住之后, 其他线程都在等待， 所以最好晚锁上，早解锁
    // mux.lock();
    while(1) {
        if (!mux.try_lock()) {
            // try_lock 会尝试获取锁，如果锁当前不可用（已被其他线程持有），
            // 它会立即返回而不会阻塞当前线程。这种方法通常用于避免线程阻塞，
            // 因为如果锁不可用，线程可以继续执行其他任务而不是等待锁变得可用
            cout << "hello" << flush << endl;
            this_thread::sleep_for(chrono::milliseconds(100));
            continue;
        }
        std::cout << "test01-----" << std::endl;
        std::cout << "test02-----" << std::endl;
        std::cout << "test03-----" << std::endl;
        mux.unlock();
    }
}

// 递归锁， 被锁住了 第二次调用lock 不会出现问题
recursive_mutex rmux;
void task1() {
    rmux.lock();
    cout << "task1 [in]" << endl;
    rmux.unlock();
}

void fun(int i) {
    while (1) {
        rmux.lock();
        task1();
        cout << i << "[in]" << endl;
        rmux.unlock();
    }
}
int main() {
    for(int i=0;i<10;i++) {
        thread th(fun, i+1);
        th.detach();
    }
    for(int i=0;i<10;i++) {
        thread th(TestThread);
        th.detach();
    }
}
