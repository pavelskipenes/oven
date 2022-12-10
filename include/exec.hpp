#pragma once
/**
 * @file exec.hpp
 * @author Pavel Skipenes (pavelgs@stud.ntnu.no)
 * @brief Execute host commands with this module
 * @version 0.1
 * @date 10-12-2022
 *
 * @copyright Copyright Pavel Skipenes (c) 2022
 *
 */
#include <string>
#include <string_view>
/**
 * @brief Execute arbitrary command on host
 *
 * @param cmd command to execute
 * @return std::string output produced from command.
 */
std::string exec(const std::string_view &cmd);
