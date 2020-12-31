/**
 * @file argparser.cpp
 * @author Pavel Skipenes (pavelgs@stud.ntnu.no)
 * @brief Module that parses and validates the arguments
 * @version 0.1
 * @date 23-12-2020
 *
 * @copyright Copyright (c) 2020
 *
 */
#include <cmath>
#include <iostream>

#include "argparser.h"

bool is_valid_load_rate(char *argv[]) {

	try {
		int load_rate;
		load_rate = round(std::stoi(argv[1]));
		if (load_rate > 101 || load_rate < 0) {
			throw std::out_of_range("value needs to be between 1 and 100");
			return false;
		}

	} catch (const std::invalid_argument &ia) {
		std::cerr << "Invalid argument: " << ia.what() << "\n";
		return false;

	} catch (const std::out_of_range &oor) {
		std::cerr << "Invalid argument: " << oor.what() << "\n";
		return false;
	}

	return true;
}

int get_load_rate(char *argv[]) {
	return round(std::stoi(argv[1]));
}
