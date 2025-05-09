#ifndef PRODUCER__H
#define PRODUCER__H
#include <iostream>
#include <thread>
#include <atomic>
#include <queue>
#include <condition_variable>
#include <mutex>
#include <string>

class Producer{
    public:
        Producer(std::queue<std::string> &buffer, std::mutex &mtx,
        std::condition_variable &cv, std::atomic<bool> &running);
        void start();
        void run();
        void stop();
    private:
    std::queue<std::string> &buffer;
    std::mutex &mtx;
    std::condition_variable &cv;
    std::atomic<bool> &running;
    std::thread thread_;

};

#endif