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

template<typename... Args>
void print(const Args&... args) {
    int a[] {(std::cout << args << ' ',0)...}; //运用数组让逗号表达式展开
}
// 递归模板
template<typename T>
void process(const T& arg) {
    std::cout << arg << ' ';
}

template<typename T, typename... Args>
void process(const T& arg, const Args&... args) {
    std::cout<< arg << ' ';
    process(args...);
}

// 递归模板求sum 思路就是拆成当前参数和型参包
template<typename T>
T sum1(const T& x) {
    return x;
}

template<typename T, typename... Args>
T sum1(const T& arg,const Args&... args) {
    return arg + sum1(args...);
}
int main() {
    sum(1, 1.2, "123");
    print(1,2,3);
    std::cout << std::endl;
    process(1, 2.3, "hello", 'c');
    std::cout << std::endl;
    std::cout << sum1(1, 2 , 3 , 4 ,100) << std::endl;
}