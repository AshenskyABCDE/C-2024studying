#include <iostream>
#include <thread>
#include <vector>

int i = 0;
void hello() {
    i++;
    std::cout<< i << std::endl;
    std::cout << "Hello Concurrent World\n";
    for (int i=0;i<10;i++) {
        std::this_thread::sleep_for(std::chrono::seconds(1));
    }
}

void byebye() {
    std::cout << "Byebye quit" << std::endl;
}
class backgroud_task {
public:
    void operator()() const {
        hello();
        byebye();
    }
};


int main() {
    std::thread t(hello);
    t.join();

    backgroud_task f;
    std::thread my_thread(f);
    my_thread.join(); // 注释这个,你会发现报错
    std::vector<std::thread>vec;
    for(int i=1;i<=10;i++) {
        vec.emplace_back(hello); // 这里要说明一下 线程是不可拷贝的，只能移动构造，所以直接push_back是不行的
    }
    for(auto& thread : vec) {
        thread.join();
    }

}