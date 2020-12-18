/**
 * @file main.cpp
 * @author Pavel Skipenes (pavelgs@stud.ntnu.no)
 * @brief 
 * @version 0.1
 * @date 18-12-2020
 *
 * @copyright Copyright (c) 2020
 * 
 */

#include <iostream>
#include <thread>
#include <chrono>
#include <cmath>

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

int main(int argc, char* argv[]){

    if(argc != 2){
        std::cout << "Usage: " << argv[0] << "load rate [1-99]\n";
        return 1;
    }

    int load_rate;
    try{
        load_rate = round(std::stoi(argv[1]));

        if(load_rate > 100 || load_rate < 0){
            throw std::out_of_range("value needs to be between 1 and 99");
        }

    }catch(const std::invalid_argument& ia){
        std::cerr << "Invalid argument: " << ia.what() << "\n";
        return 1;
    }catch(const std::out_of_range& oor){
        std::cerr << "Invalid argument: " << oor.what() << "\n";
        return 1;
    }

    oven(load_rate);

    return 0;
}
