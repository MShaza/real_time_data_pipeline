#include "consumer.hpp"

Consumer::Consumer(std::queue<std::string> &buffer, 
std::mutex &mtx, std::condition_variable &cv, 
std::atomic<bool> &running) : buffer(buffer), mtx(mtx), cv(cv), running(running)
{}

void Consumer::start(){
    _thread = std::thread(&Consumer::run, this);
}
void Consumer::run(){
    while (running || !buffer.empty()) {
    std::unique_lock<std::mutex> lock(mtx);
    cv.wait(lock, [&] { return !buffer.empty() || !running; });
    while (!buffer.empty()) {
    std::string data = buffer.front();
    std::cout << "[Consumer Thread ID: " << std::this_thread::get_id() << "] Consumed: " << data << std::endl;
    buffer.pop();
    lock.unlock();

    // process(data);

    lock.lock(); // Re-lock before checking queue again
        }
    }
}
void Consumer::stop(){
    if(_thread.joinable()){
        _thread.join();
    }
}