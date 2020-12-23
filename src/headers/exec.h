#pragma once
/**
 * @file exec.h
 * @author Pavel Skipenes (pavelgs@stud.ntnu.no)
 * @brief Execute host commands with this module
 * @version 0.1
 * @date 23-12-2020
 * 
 * @copyright Copyright (c) 2020
 * 
 */
#include <string>

/**
 * @brief Execute arbitrary command on host
 * 
 * @param cmd command to execute
 * @return std::string output produced from command.
 */
std::string exec(const char* cmd);
