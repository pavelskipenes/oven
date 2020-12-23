#include <chrono>
#include <thread>
#include <atomic>
#include <csignal>

#include "oven.h"

static std::atomic<bool> terminate_threads(false);
static void oven_thread(int load_rate, std::atomic<bool>* terminate_ptr);
static void signalHandler(int signum);

void oven(int load_rate){
    signal(SIGINT, signalHandler);
    std::thread thread(oven_thread, load_rate, &terminate_threads);
    thread.join();
}

void signalHandler(int signum) {
    (void)signum; // suppress unused parameter warning
    terminate_threads = true;
}

void oven_thread(int load_rate, std::atomic<bool>* terminate_ptr){

    using namespace std::chrono_literals;
    const std::chrono::milliseconds CYCLE_TIME = 100ms;

    while(!terminate_ptr->load()){
        auto start = std::chrono::high_resolution_clock::now();
        auto now = std::chrono::high_resolution_clock::now();
        auto diff = now - start;

        while(true){
            now = std::chrono::high_resolution_clock::now();
            diff = now - start;
            if(diff > (float)load_rate/100 * CYCLE_TIME){
                break;
            }
            // TODO: useless power-consuming non-memory instructions
        }

        std::this_thread::sleep_for(CYCLE_TIME - diff);
    }
}
