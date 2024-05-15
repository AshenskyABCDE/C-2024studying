#include <iostream>

template<typename T>
class Vector {
private:
    T* data;
    int capacity;
    int size;
    void resize(int new_capacity) {
        T* new_data = new T[new_capacity];
        for(int i=0;i< size;i++){
            new_data[i] = data[i];
        }
        delete[] data;
        data = new_data;
        capacity = new_capacity;
    }
public:
    Vector() : data(nullptr) , capacity(0) , size(0){}
    ~Vector() {
        delete[] data;
    }
    void push_back(const T& value) {
        if(size == capacity) {
            if (size == 0) {
                resize(1);
            } else {
                resize(capacity * 2);
            }
        }
        data[size++] = value;
    }
    T& operator[](int index) {
        if(index <= size)
        return data[index];
    }
};
int main() {
    Vector<int> vec;
    for(int i=1;i<=10;i++) {
        vec.push_back(i);
    }
    for(int i=0;i<=9;i++){
        std::cout << vec[i] << std::endl;
    }
}