/**
 * @file argparser.cpp
 * @author Pavel Skipenes (pavelgs@stud.ntnu.no)
 * @brief Module that parses and validates the arguments
 * @version 0.1
 * @date 10-12-2022
 *
 * @copyright Copyright Pavel Skipenes (c) 2022
 *
 */
#include <cmath>
#include <iostream>
#include <optional>
#include <sstream>
#include <string>
#include <variant>

#include "argparser.hpp"
std::variant<int, std::string> get_load_rate(const std::string_view &user_input)
{
    int load_rate = 0;
    try
    {
        load_rate = static_cast<int>(round(std::stoi(std::string(user_input.data()))));
        const auto MAX_LOAD_RATE = 100;
        if (load_rate > MAX_LOAD_RATE || load_rate < 1)
        {
            return std::string("[ERROR]: [LOAD] needs to be between 1 and 100\n");
        }
    }
    catch (const std::invalid_argument &ia)
    {
        // thrown by round()
        std::stringstream ss;
        ss << "Invalid argument: " << ia.what() << "\n";
        return ss.str();
    }
    catch (const std::out_of_range &oor)
    {
        // thrown by round()
        std::stringstream ss;
        ss << "Invalid argument: " << oor.what() << "\n";
        return ss.str();
    }

    return load_rate;
}
