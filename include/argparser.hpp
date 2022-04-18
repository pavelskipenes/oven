#pragma once
/**
 * @file argparser.hpp
 * @author Pavel Skipenes (pavelgs@stud.ntnu.no)
 * @brief Module that parses and validates the arguments
 * @version 0.1
 * @date 23-12-2020
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
int get_load_rate(char *argv[]);
/**
 * @brief Validates valid load rate.
 *
 * @param argv user input
 * @return true on valid input
 * @return false on invalid input
 */
bool is_valid_load_rate(char *argv[]);
