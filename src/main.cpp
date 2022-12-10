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

int main(int argc, char *argv[])
{

    if (argc != 2 || !is_valid_load_rate(argv))
    {
        std::cout << "usage: " << argv[0] << " [1 - 100]\n";
        return EXIT_FAILURE;
    }

    oven(get_load_rate(argv));
    return EXIT_SUCCESS;
}
