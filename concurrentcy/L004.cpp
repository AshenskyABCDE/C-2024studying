#include <iostream>
#include <thread>

using namespace std;

void ThreadMain(int x, string s, double p1) {
    std::cout << x << ' ' << s << ' ' << p1 << endl;
}


class Obj {
public:
    Obj() {
        std::cout << "构造函数" << std::endl;
    }
    Obj(const Obj&) {
        std::cout << "拷贝构造" << std::endl;
    }
    ~Obj() {
        std::cout << "析构函数" << std::endl;
    }
    string name;
};

void Threadfun1(int x, Obj A) {
    std::cout << endl; // 这里拷贝构造了2次
    std::cout << x << " " << A.name << std::endl; // A.name变量的生命周期可能早于线程生命周期销毁 所以访问不到
}

void Threadfun2(Obj *A) {
    this_thread::sleep_for(chrono::milliseconds(1000));
    std::cout << A->name << std::endl;
}

int main() {
    // thread的传参
    thread th(ThreadMain, 1, "123", 1.0);
    th.join();
    Obj p;
    p.name = "12346";
    thread test(Threadfun1, 1, p); // 析构了3次
    test.join();

    std::cout << "---------" << std::endl;

    {
        Obj A;
        A.name = "12345";
        thread test1;
        test1 = thread(Threadfun2, &A);
        test1.join();
    }
    //getchar();
}