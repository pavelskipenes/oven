/**
 * @file core_count.cpp
 * @author Pavel Skipenes (pavelgs@stud.ntnu.no)
 * @brief Module that get the amount of cores from the host
 * @version 0.1
 * @date 10-12-2022
 *
 * @copyright Copyright Pavel Skipenes (c) 2022
 *
 */
#include <iostream>

#include "core_count.hpp"
#include "exec.hpp"

int get_core_count()
{
    int number_of_cores = 1;
    try
    {
#ifdef __USE_POSIX2
        number_of_cores = std::stoi(exec("/usr/bin/nproc"));
#else
#warning "Unsupported system. Defaulting to only one core."
#endif
    }
    catch (const std::runtime_error &e)
    {
        std::cerr << e.what() << '\n';
        std::cerr << "Could not find out the number of cores on the host.\n";
        std::cerr << "Falling back to using one core.\n";
    }
    return number_of_cores;
}
