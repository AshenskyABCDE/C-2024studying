#include <iostream>
#include <thread>
#include <string>
#include <mutex>

using namespace std;

void SystemInit() {
    cout << "hello" <<endl;
}

void SystemInitOne() {
    static std::once_flag flag;
    std::call_once(flag, SystemInit);
}

int main() {
    // 如何保证只运行一次？
    SystemInitOne();
    SystemInitOne();

    for(int i=0;i<=4;i++) {
        thread th(SystemInitOne);
        th.detach();
    }
}