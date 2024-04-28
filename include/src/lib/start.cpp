#include <iostream>
using namespace std;

template <class T>
void Swap(T &a, T &b) {
    T c = a;
    a = b;
    b = c;
}

class Complex {
    double real, imag;
public:
    Complex (double real, double imag) : real(real), imag(imag) {}
    friend ostream& operator<<(ostream &cout, const Complex &c);
};

ostream& operator <<(ostream &cout, const Complex &c) {
    cout << c.real << "+" << c.imag << "i" << endl;
    return cout;
}

int main(){

    Complex complex(0.156, 0.123);
    cout << complex;
}