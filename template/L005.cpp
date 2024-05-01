#include <iostream>

template<typename T>
struct A {
public:
    A(T v) : x ( v ) {}
private:
    T x;
};

A(int) -> A<std::size_t>; // 根据用户定义类型来推导类型

int main() {
    A t {1};
    std::cout << std::is_same<decltype(t) , A<std::size_t>>::value << std::endl;
}
