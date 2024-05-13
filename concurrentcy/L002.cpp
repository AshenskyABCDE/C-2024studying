#include <iostream>
#include <thread>

void ThreadMain() {
    std::cout << "begin" << std::this_thread::get_id() << std::endl;
    for (int i=0 ;i< 10 ;i++) {
        std::cout << i << std::endl;
        std::this_thread::sleep_for(std::chrono::seconds(1));
    }
    std::cout << " end " << std::this_thread::get_id() << std::endl;
}

void Threadfun1() {
    std::cout << " thread 1 " << std::endl; 
}

void Threadfun2() {
    std::cout << " thread 2 " << std::endl;
}
int main() {
    // 了解一下 主线程和子线程
    std::cout << "main thread id " << std::this_thread::get_id() << std::endl; // main函数里面是主线程 创建的是子线程
    std::thread th(ThreadMain);

    std::cout << "wait" << std::endl;
    th.join();
    std::cout << "wait" << std::endl;
    return 0;
}