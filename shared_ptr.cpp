#include <iostream>
#include <memory>
#include <utility>
template <typename T>
class smater_ptr {
public:
    explicit smater_ptr(T* ptr = nullptr) :ptr_(ptr), count_(new int(1)) {}
    ~smater_ptr() {
        --(*this->count_);
        if( (*this->count_) == 0) {
            delete ptr_;
            ptr_ = nullptr;
            delete count_;
            count_ = nullptr;
        }
    }

    smater_ptr(const smater_ptr& s) : ptr_(s.ptr) , count_(s.count_) {
        *(count_) ++;
    }
    smater_ptr<T>& operator=(const smater_ptr& s) {
        if( this != &s) {
            if(-- (* (this->count)) == 0) {
                delete this->ptr_;
                delete this->count_;
            }
            ptr_ = s.ptr_;
            count_ = s.count_;
            *count_ ++;
        }
        return *this;
    }
    T& operator* () {
        return *(this->ptr_);
    }
    T* operator->(){
        return this->ptr_;
    }
    T* get() const {
        return ptr_;
    }

private:
    T* ptr_;
    int* count_;
};

int main(){
    smater_ptr<int> ptr1 (new int (5));

    std::cout<< *ptr1 << std::endl;
}