#include <thread>
#include <iostream>
#include <chrono>

bool is_exit = false;
void ThreadMain() {
    while (!is_exit) {
        std::cout << "ThreadMain" << std::endl;
        std::this_thread::sleep_for(std::chrono::milliseconds(100));
    }
}

int main() {
    // {
    //     std::thread th(ThreadMain);
    // } (1) 这里由于主线程运行结束 但是子线程仍在运行，因此会报错
    {
        std::thread th(ThreadMain);
        th.detach();
    } // (2) detach能让主线程与子线程分开，但也存在问题，主线程退出但是子线程未退出

    {
        std::thread th(ThreadMain);
        th.join();
    } // (3) join能等待子线程，主线程阻塞
}