#include <iostream>

void test(int& x) {
    std::cout << "Lvalue" << std::endl;
}

void test(int&& x) {
    std::cout << (&x) << std::endl;
    std::cout << "Rvalue-" << std::endl;
    // 也就是说那种临时变量， 
}

template <typename T>
void func (T&& x) { // 万能引用，能判断出传进来的是左值还是右值
    //T&& x, T&&是一个类型，x被当成左值，这也就是std::move(x)传进来下面调用函数时发现调用成右值的原因
    //T&& x = 100， 100才是右值！所以要想保证原来的左值右值，使用forward！
    std::cout << (&x) << std::endl;
    test(std::forward<T>(x)); 
    test(x);
    std::cout << "---------" << std::endl;
}

int main(){
    int x = 10;
    int& y = x;
    func(x);// 左值
    func(y);
    func(123);

    func(std::move(x));
    std::cout << "move(x) is ???? ";
    test(std::move(x));
    std::cout << std::endl;
    /*
    上述运行结果
            Lvalue
            Lvalue
            ---------
            Lvalue
            Lvalue
            ---------
            Rvalue
            Lvalue
            ---------
            move(x) is ???? Rvalue
    */
    // 通过这样的例子，你可以发现std::forward可以保证原来的左右值，而进行完美转发
}