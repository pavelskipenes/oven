/**
 * @file core_count.cpp
 * @author Pavel Skipenes (pavelgs@stud.ntnu.no)
 * @brief Module that get the amount of cores from the host
 * @version 0.1
 * @date 23-12-2020
 * 
 * @copyright Copyright (c) 2020
 * 
 */

#include <iostream>
#include <exec.h>

#include "core_count.h"

int get_core_count(){
    int number_of_cores;
    try
    {
        #ifdef unix
            number_of_cores = std::stoi(exec("/usr/bin/nproc"));
        #else
            // TODO: windows implementation
        #endif
    }
    catch(const std::runtime_error& e)
    {
        std::cerr << e.what() << '\n';
        std::cerr << "Could not find out the number of cores on the host.\n";
        std::cerr << "Falling back to using one core.\n";
        number_of_cores = 1;
    }
    
    return number_of_cores;
}
