#include <iostream>
#include <utility>

int main() {
    char *s = "abcdefeafaefe";
    std::cout << sizeof(s) << std::endl;
    char ss[] = {'a', 'b', 'c', 'd' , 'e'};
    std::cout << sizeof(ss) << std::endl;
    int a[] = {1, 2, 4 ,5,6};
    std::cout << sizeof(a) << std::endl;  
    
}