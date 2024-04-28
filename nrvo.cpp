#include <bits/stdc++.h>
using namespace std;
class Obj {
public:
    Obj() {
        cout<<"obj"<<endl;
    }
    Obj(const Obj&) {
        cout<<"obj&"<<endl;
    }   
    Obj(Obj&&) {
        cout<<"obj&&"<<endl;
    }
};


void process(int& i) {
    cout<<"Lvalue reference: "<<i<<endl;
}

void process(int&& i) {
    cout<<"Rvalue reference: "<<i<<endl;
}
Obj func1() {
    Obj A;
    return A;
}

Obj func2() {
    Obj A;
    return move(A);
}

Obj func3() {
    Obj A;
    Obj B;
    int n = 100;
    if(n %2 == 1) {
        return A;
    } else {
        return B;
    }
}

class Resource {
public:
    Resource() : data_(nullptr) {}
    Resource(int* data) : data_(data) {}
    ~Resource() {
        delete data_;
    }

    // 移动构造函数
    Resource(Resource&& other) noexcept : data_(other.data_) {
        other.data_ = nullptr;
    }

    // 移动赋值运算符
    Resource& operator=(Resource&& other) noexcept {
        if (this != &other) {
            delete data_;
            data_ = other.data_;
            other.data_ = nullptr;
        }
        return *this;
    }

    void print() const {
        std::cout << "Data: " << (data_ ? *data_ : 0) << std::endl;
    }

private:
    int* data_;
};
int main() {
    cout<<"-------1-------"<<endl;
    func1();
    cout<<"--------2------"<<endl;
    func2();
    cout<<"-------3------"<<endl;
    func3();

    int x = 100;
    process(x);
    process(move(x));
    process(x);

    int* ptr = new int(42);
    Resource resource1(ptr); // 创建资源对象 resource1

    Resource resource2 = std::move(resource1); // 使用 std::move() 将 resource1 转移到 resource2 中

    std::cout << "Resource1 after move:" << std::endl;
    resource1.print(); // 打印 resource1，这里将会输出 0，因为 resource1 的资源已经被转移了

    std::cout << "Resource2 after move:" << std::endl;
    resource2.print();
}