#include <iostream>
#include <memory>

class A {
public:
    virtual void func1() {
        std::cout << "123" << std::endl;
    }
    virtual void func2() {
        std::cout << "123" << std::endl;
    }
    virtual void func3() {
        std::cout << "123" << std::endl;
    } 
};

class B : A {
public:
    void func1() {
        std::cout << "456" << std::endl;
    } 
};

int main(){
    A a;
    B b;
    a.func1();
    b.func1();
    void** ptr = *(void***)&a;
    std::cout << &a << std::endl;
    std::cout << ptr << std::endl;
    std::cout << *reinterpret_cast<void***>(&a) << std::endl;
    std::cout << (int*)*(int*)&a << std::endl;
}