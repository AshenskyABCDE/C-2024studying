#include <bits/stdc++.h>
using namespace std;
template <int n>
struct fac {
    static const int value = n * fac<n-1>::value;
};

template <>
struct fac<0> {
    static const int value = 1;
};
int main() {
    cout<<fac<10>::value<<endl;
}