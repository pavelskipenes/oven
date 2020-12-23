/**
 * @file main.cpp
 * @author Pavel Skipenes (pavelgs@stud.ntnu.no)
 * @brief Just main
 * @version 0.1
 * @date 18-12-2020
 *
 * @copyright Copyright (c) 2020
 *
 */

#include <iostream>

#include "oven.h"
#include "argparser.h"

int main(int argc, char* argv[]){

    if(argc != 2){
        std::cout << "Usage: " << argv[0] << "load rate [1-100]\n";
        return EXIT_FAILURE;
    }

    if(!is_valid_load_rate(argv)){
        return EXIT_FAILURE;
    }

    oven(get_load_rate(argv));

    return EXIT_SUCCESS;
}
