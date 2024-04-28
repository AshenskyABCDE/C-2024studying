#include <iostream>
using namespace std;

class Vector {
    int  *data;
    size_t  my_size;
public:
    explicit Vector(size_t n) {
        data = new int[n]{};
        my_size = n;
    }

    int const &operator[](size_t i) const {
        return data[i];
    }

    void resize(size_t n) {
        int *oid_data = data;
        data = new int[n]{};
        size_t old_size = my_size;
        my_size = n;
        memcpy(data, oid_data, my_size * sizeof(int));
    }
    size_t size() const {
        return my_size;
    }

    ~Vector(){
        delete[] data;
    }
};

int main() {
    Vector arr(3);
    for(int i=0; i<arr.size(); i++) {
        cout<<arr[i]<<" ";
    }
}