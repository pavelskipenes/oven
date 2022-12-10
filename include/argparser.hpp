#pragma once
#include <string_view>
#include <variant>

/**
 * @file argparser.hpp
 * @author Pavel Skipenes (pavelgs@stud.ntnu.no)
 * @brief Module that parses and validates the arguments
 * @version 0.1
 * @date 10-12-2022
 *
 * @copyright Copyright Pavel Skipenes (c) 2022
 *
 */
/**
 * @brief Get the load rate
 * @warning Make sure to call @c is_valid_load_rate first to validate input
 * @param argv console input
 * @return int
 */

/**
 * @brief
 *
 * @param load_rate user supplies load rate
 * @return std::variant<int, std::string> parsed load rate or an error string with error message
 */
std::variant<int, std::string> get_load_rate(const std::string_view &load_rate);