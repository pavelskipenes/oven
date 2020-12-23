#include <chrono>
#include <thread>

#include "oven.h"

void oven(int load_rate){

    using namespace std::chrono_literals;
    const std::chrono::seconds CYCLE_TIME = 1s;

    while(true){
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
