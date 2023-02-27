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
#include <string_view>

#include "core_count.hpp"
#include "exec.hpp"

int get_core_count()
{
    int number_of_cores = 1;

    // Bug: This check only if the compilation is done on a posix complient system.
    // This check should be run time because users might cross compile the application.
    try
    {
#ifdef __USE_POSIX2
        // Bug: In Alpine Linux nproc is not available. Maybe check if the file exists?
        number_of_cores = std::stoi(exec(std::string_view("/usr/bin/nproc")));
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
