#include <iostream>

// 简单的模板 但是a和b必须是一个类型
template<typename T>
T max(T a, T b) { // T max(T a, T2 b) 试试
    return a > b ? a : b;
}

//怎么根据变量类型具体实现相关内容？
template<typename T>
void func(int x) {
    std::cout << " 123 " << std::endl;
}

template<typename T>
void func(T x) {
    std::cout << " 123465 " <<std::endl;
}

template<typename T>
void func(std::string x) {
    std::cout << " 123465111 " <<std::endl;
}

//如果想合到一起呢？用is_same decltype，这叫做类型萃取 判断变量类型是否相同
template<typename T>
void func1(T x) {
    int y;
    if ( std::is_same<decltype(x) , decltype(y)>::value ) { // 等同于 std::is_same<decltype(x) , int>::value
        std::cout << "int" << std::endl;
    } else {
        std::cout<< "dont int a" << std::endl;
    }
}
int main() {
    // 
    // int x = max(1, 2);
    func<int>(1); // 123
    func<double>(1.0); // 123465
    func<std::string>("123");// 123465111

    std::cout << "---------" << std::endl;
    func1<int>(1);
    func1<std::string>("123");
}