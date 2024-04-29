#include <iostream>
#include <bits/stdc++.h>

template<typename RT, typename T1, typename T2>
RT Max(T1 a , T2 b) {
    return a > b ? a : b;
}

// 如何自动推导返回值类型？
template<typename T1, typename T2> // auto -> 尾推导值
auto Maxx(T1 a , T2 b) -> decltype(a > b ? a : b) {
    return a > b ? a : b;
}

template<typename T1, typename T2, typename RT = decltype(true ? T1{} : T2{})> // 构造临时对象来判断
RT Maxxx(T1 a , T2 b) {
    return a > b ? a : b;
}

template<typename T1, typename T2>
const auto max_auto(T1 a , T2 b) {
    return a > b ? a : b;
}

template<typename T1, typename T2> 
decltype(auto) max1(T1 a, T2 b) {
    return a > b ? a : b;
}

int main() {
    std::cout << Max<double>(1,1.2) << std::endl;
    std::cout << Maxx(1,1.2) << std::endl;
    std::cout << Maxxx(1,1.2) << std::endl;
    std::cout<< "step1 over next is step2" << std::endl;

    // cv限定符，你会发现如果你想保持const这个类型，你会发现是有问题 下面这个代码直观的感受 不是我想要的const类型，需要加const 
    const int x = 1;
    const double y = 1.12;
    decltype(Max<const double>(x, y)) result1 = Max<const double>(x, y);
    result1 = 2.2;
    std::cout << typeid(result1).name() << std::endl;
    auto result2 = Maxx(x,y);
    result2 = 2.2;
    std::cout << result2 << std::endl;
    auto result3 = Maxxx(x,y);
    result3 = 2.2;
    std::cout << result3 << std::endl;
    auto result5 = max_auto(x,y);
    result5 = 4;
    std::cout << result5 << std::endl;
    auto result4 = max1(x,y);
    result4 = 2.2;
    std::cout << result4 << std::endl;

    const auto result6 = max1(x,y);
    result6 = 1.2;
}