//https://zh.cppreference.com/w/cpp/language/parameter_pack

#include <iostream>

void func1 (int x, double xx , const char* xxx) {
    // 为何string 能隐式转换 const char* 转换不了char*呢？

    std::cout << "func1" << std::endl;
}

void func1 (int* x, double* xx, const char** xxx) {
    std::cout << "&func1" << std::endl;
}
template<typename... Args> //Args是类型型参包，变量名可以自己改，里面存放的是对应的变量类型
void sum(Args... args) { // args是函数型参包，变量名也可以自己改，里面存放的是对应的参数
    func1(args...);// ....
    func1(&args...);
    // 你可以发现...就是展开的意思，专有名词就叫包展开
}

int main() {
    sum(1, 1.2, "123");
}