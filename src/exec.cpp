/**
 * @file exec.cpp
 * @author Pavel Skipenes (pavelgs@stud.ntnu.no)
 * @brief Execute host commands with this module
 * @version 0.1
 * @date 10-12-2022
 *
 * @copyright Copyright Pavel Skipenes (c) 2022
 *
 */
#include <array>
#include <iostream>
#include <memory>

#include "exec.hpp"

std::string exec(const std::string &cmd)
{
    std::string result;
    std::shared_ptr<FILE> pipe(popen(cmd.c_str(), "r"), pclose);

    if (!pipe)
    {
        throw std::runtime_error("popen() failed!");
    }
    std::array<char, 128> buffer;
    while (!feof(pipe.get()))
    {
        if (fgets(buffer.data(), 128, pipe.get()) != nullptr)
        {
            result += buffer.data();
        }
    }
    return result;
}
