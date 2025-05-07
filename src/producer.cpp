#include "producer.hpp"

Producer::Producer(std::queue<std::string> &buffer,
std::mutex &mtx, std::condition_variable &cv, 
std::atomic<bool> &running) : buffer(buffer), mtx(mtx), cv(cv), running(running) {}

void Producer::start(){
    thread_ = std::thread(&Producer::run, this);
}

void Producer::run(){
    int count = 0;
    while(running){
        std::ostringstream oss;
        oss << "Data - "<< count++;
        {
            std::lock_guard<std::mutex> lock(mtx);
            buffer.push(oss.str());
        }
        cv.notify_one();
        std::this_thread::sleep_for(std::chrono::milliseconds(500));
    }
}

void Producer::stop(){
    if(thread_.joinable()){
        thread_.join();
    }
}