#ifndef CONSUMER_H
#define CONSUMER_H

#include <thread>
#include <atomic>
#include <queue>
#include <condition_variable>
#include <mutex>
#include <string>
#include <iostream>

 class Consumer{
    private:
        std::queue<std::string> &buffer;
        std::condition_variable &cv;
        std::mutex &mtx;
        std::atomic<bool> &running;
        std::thread _thread;
    public:
    Consumer(std::queue<std::string> &buffer, std::mutex &mtx,
        std::condition_variable &cv, std::atomic<bool> &running);
        void start();
        void run();
        void stop();
 };


#endif