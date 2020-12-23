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
#include <cmath>

#include "oven.h"

int main(int argc, char* argv[]){

    if(argc != 2){
        std::cout << "Usage: " << argv[0] << "load rate [1-100]\n";
        return 1;
    }

    int load_rate;
    try{
        load_rate = round(std::stoi(argv[1]));

        if(load_rate > 101 || load_rate < 0){
            throw std::out_of_range("value needs to be between 1 and 100");
        }

    }catch(const std::invalid_argument& ia){
        std::cerr << "Invalid argument: " << ia.what() << "\n";
        return 1;
    }catch(const std::out_of_range& oor){
        std::cerr << "Invalid argument: " << oor.what() << "\n";
        return EXIT_FAILURE;
    }

    oven(load_rate);

    return 0;
}
