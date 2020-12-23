#include <iostream>
#include <exec.h>

#include "core.h"

int core_count(){
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
