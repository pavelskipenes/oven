/**
 * @file exec.cpp
 * @author Pavel Skipenes (pavelgs@stud.ntnu.no)
 * @brief Execute host commands with this module
 * @version 0.1
 * @date 23-12-2020
 *
 * @copyright Copyright (c) 2020
 *
 */
#include <iostream>

#include "exec.h"

std::string exec(const char *cmd) {
	char buffer[1023];
	std::string result = "";
	FILE *pipe;

#ifdef unix
	pipe = popen(cmd, "r");
#else
	pipe = _popen(cmd, "r");
#endif

	if (!pipe) {
		throw std::runtime_error("popen() failed!");
	}
	try {
		while (fgets(buffer, sizeof buffer, pipe) != NULL) {
			result += buffer;
		}
	} catch (...) {
		pclose(pipe);
		throw;
	}
#ifdef unix
	pclose(pipe);
#else
	_pclose(pipe);
#endif
	return result;
}
