#include <iostream>
#include <condition_variable>
#include <vector>
#include <queue>
#include <stack>
#include <thread>

std::queue<int> q;
std::mutex mtx;
std::condition_variable cv;

void producer() {

    q.push(1);
    q.push(2);
    q.push(3);
    q.push(4);
    q.push(5);
}

void consumer(int id) {
    while (true) {
        int gift = q.front();
        std::cout << "小朋友 " << id << "得到了 " << gift << '\n';
        q.pop();
        if(q.size() == 0) {
            break;
        }
    }
}

int main() {
    std::jthread producer1_thread(producer);
    std::vector<std::jthread> consumer_threads;
    for(int i = 0; i < 32; i++){
        std::jthread consumer_thread(consumer, i);
        consumer_threads.push_back(std::move(consumer_thread));
    }
    return 0;
}