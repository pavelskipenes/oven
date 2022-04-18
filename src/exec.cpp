/**
 * @file exec.cpp
 * @author Pavel Skipenes (pavelgs@stud.ntnu.no)
 * @brief Execute host commands with this module
 * @version 0.1
 * @date 23-12-2020
 *
 * @copyright Copyright Pavel Skipenes (c) 2022
 *
 */
#include <iostream>

#include "exec.hpp"

std::string exec(const char *cmd)
{
    std::string result = "";
    FILE *pipe;

#ifdef unix
    pipe = popen(cmd, "r");
#else
    pipe = _popen(cmd, "r");
#endif

    if (!pipe)
    {
        throw std::runtime_error("popen() failed!");
    }
    try
    {
        char buffer[1023];
        while (fgets(buffer, sizeof buffer, pipe) != NULL)
        {
            result += buffer;
        }
    }
    catch (...)
    {
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
