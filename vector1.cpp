#include <iostream>

template<typename T>
class Vector {
public:
    Vector(int initial_capacity = 10) : sz(0), capacity(initial_capacity) {
        arr = new T*[capacity];
    }

    ~Vector() {
        delete[] arr;
    }

    void push(const T& x) {
        if (sz == capacity) {
            // 如果当前大小已经达到容量上限，则进行扩容
            capacity *= 2;
            T** new_arr = new T*[capacity];
            for (int i = 0; i < sz; ++i) {
                new_arr[i] = arr[i];
            }
            delete[] arr;
            arr = new_arr;
        }
        arr[sz++] = new T(x);
    }

    void erase(int pos) {
        if (pos < 0 || pos >= sz) return;
        delete arr[pos];
        for (int i = pos; i < sz - 1; ++i) {
            arr[i] = arr[i + 1];
        }
        --sz;
    }

    T get(int pos) {
        if (pos < 0 || pos >= sz) {
            // 返回一个无效引用以表示越界
            static T invalid;
            return invalid;
        }
        return *arr[pos];
    }

    int size() const {
        return sz;
    }

private:
    T** arr;
    int sz;
    int capacity;
};

int main() {
    Vector<int> vec;
    for (int i = 1; i <= 20; ++i) {
        vec.push(i);
    }
    for (int i = 0; i < vec.size(); ++i) {
        std::cout << vec.get(i) << std::endl;
    }
    return 0;
}
