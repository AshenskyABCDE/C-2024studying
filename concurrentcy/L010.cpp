#include <iostream>
#include <mutex>
#include <thread>
#include <vector>

std::mutex gmutex;
int counter = 0;

void SafeIncrement(int thread_id) {
    for (int i = 0; i < 10; ++i) {
        std::lock_guard<std::mutex> lock(gmutex);
        ++counter;
        std::cout << "Thread " << thread_id << " incremented counter to " << counter << std::endl;
    }
}

int main() {
    std::vector<std::thread> threads;

    for (int i = 0; i < 5; ++i) {
        threads.emplace_back(SafeIncrement, i);
    }

    for (auto& th : threads) {
        th.join();
    }

    std::cout << "Final counter value: " << counter << std::endl;

    return 0;
}
