#include <thread>
#include <iostream>
#include <string>

using namespace std;
class X1 {
public:
    void Start() {
         th = thread(&X1::func, this);
         th.join();
        thread tt([this]() {std::cout << "hello t2" << std::endl;});
        tt.join();
    }
    void func() {
        std::cout << "hello t1" << std::endl;
    }
private:
    thread th;
};

int main() {
    // lambda函数作为线程入口
    // 如果你会C++基础的话，可以知道分为[] 和 () 前者& 代表引用传参， =为等值传参，不传进来就是空， 后者里面传变量参数

    thread th([](int x){
        cout << "pthred " << x << std::endl;
    }, 123);
    th.join();

    X1 test;
    test.Start();
}