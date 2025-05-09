#include <iostream>
#include "producer.hpp"
#include "consumer.hpp"
int main(){
    std::cout<<"Pipeline starting..." << std::endl; 

    std::queue<std::string> buffer;
    std::mutex mtx;
    std::atomic<bool> running(true);
    std::condition_variable cv;

    Producer Producer(buffer, mtx, cv, running);
    Consumer Consumer(buffer, mtx, cv, running);
    Producer.start();
    Consumer.start();

    std::this_thread::sleep_for(std::chrono::seconds(5));
    // Now stop everything
    {
        std::lock_guard<std::mutex> lock(mtx);
        running = false;
    }
    cv.notify_all(); // wake up any waiting threads

    Producer.stop();
    Consumer.stop();
    


    return 0;
    
}