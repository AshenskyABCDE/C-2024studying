#include <iostream>
#include <thread>

using namespace std;
class A {
public:
    string name = "zzz1234";
    int num = 10000;
    void func() {
        std::cout << name << " " << num << std::endl;
    }
};

// 封装基类线程
class X1 {
public:
    void Start() {
        is_exit_ = false;
        th_ = thread(&X1::func, this);
    }
    void Wait() {
        if (th_.joinable()) {
            th_.join();
        }
    }
    void Stop() {
        is_exit_ = true;
        Wait();
    }
    bool is_exit() { return is_exit_; }
private:
    virtual void func() = 0;
    bool is_exit_ = false;
    thread th_;
};

class X2 : public X1{
    void func() override {
        while( !is_exit() ) {
            std::cout << "hello" << std::endl;
            std::this_thread::sleep_for(std::chrono::milliseconds(100));
        }
     }
    string name;
};
int main() {
    //  以派生类的成员函数作为线程入口
    X2 test1;
    test1.Start();
    std::this_thread::sleep_for(std::chrono::milliseconds(100));
    test1.Stop();
    test1.Wait();
    
    // 对类的成员函数作为线程入口
    A test;
    thread th(&A::func, &test);// 传递要传的成员函数以及在哪个类上调用这个成员函数
    th.join();
}