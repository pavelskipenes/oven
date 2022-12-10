/**
 * @file main.cpp
 * @author Pavel Skipenes (pavelgs@stud.ntnu.no)
 * @brief Just main
 * @version 0.1
 * @date 10-12-2022
 *
 * @copyright Copyright Pavel Skipenes (c) 2022
 *
 */
#include <iostream>

#include "argparser.hpp"
#include "oven.hpp"

void usage_and_exit(const std::string_view &program_name)
{
    std::cout << "usage: " << program_name << " [load]\n";
    std::cout << "[load] desired cpu load between 1 - 100 percent across all cores. \n";
    exit(EXIT_FAILURE);
}

int main(const int argc, const char *argv[])
{
    const std::string_view program_name = argv[0];
    if (argc != 2)
    {
        usage_and_exit(program_name);
    }

    const std::string_view maybe_load_rate = argv[1];
    auto load_rate_or_error = get_load_rate(maybe_load_rate);

    switch (load_rate_or_error.index())
    {
    case 0: // load_rate
        oven(std::get<int>(load_rate_or_error));
        break;

    case 1: // error
        std::cerr << std::get<std::string>(load_rate_or_error);
        usage_and_exit(program_name);
        break;
    default:
        abort();
    }

    return EXIT_SUCCESS;
}
