#include <iostream>

template <typename T>
class Vector {
private:
    int size;
    int capacity;
    T* data ;
    void resize( int new_capacity ) {
        T* new_data = new T[new_capacity];
        for(int i=0;i < size;i++) {
            new_data[i] = data[i];
        }
        delete[] data;
        data = new_data;
        capacity = new_capacity;
    }
public:
    Vector() : data(nullptr), size(0) , capacity(0) {}
    ~Vector() {
        delete[] data;
    }

    void push_back(const T& value) {
        if(size == capacity) {
            if(size == 0) {
                resize(1);
            } else {
                resize(capacity * 2);
            }
        }
        data[size++] = value;
    }

    void erase(int pos) {
        if( pos >= size || pos < 0) return ;
        for(int i=pos-1;i<size-1;i++){
            data[i] = data[i+1];
        }
        size -- ;
    }

    T& operator[] (int index) {
        if (index < size)
        return data[index];
    }
};

int main() {
    Vector<int>vec;
    for(int i=0;i<10;i++) {
        vec.push_back(i);
    }
    for(int i=0;i<10;i++) {
        std::cout << vec[i] << std::endl;
    }
    std::cout << "---------------------erase------------" << std::endl;
    vec.erase(5);
    for(int i=0;i<10;i++) {
        std::cout << vec[i] << std::endl;
    } 
}