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
#include <sstream>
#include <string_view>

#include "exec.hpp"

std::string exec(const std::string_view &cmd)
{
    std::shared_ptr<FILE> pipe(popen(std::string(cmd).data(), "r"), pclose);

    if (!pipe)
    {
        throw std::runtime_error("popen() failed!");
    }
    const auto BUFF_LEN = 128;
    std::array<char, BUFF_LEN> buffer = {};
    std::stringstream ss;
    while (!feof(pipe.get()))
    {
        if (fgets(buffer.data(), BUFF_LEN, pipe.get()) != nullptr)
        {
            ss << buffer.data();
        }
    }
    return ss.str();
}
