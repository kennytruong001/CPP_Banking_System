#ifndef UTILS_H
#define UTILS_H

/**
 * @file utils.h
 *
 * @brief This is a static function class that handles extra util/helper functions
 *
 * @author Richard Duong & Kenny Truong
 */


// standard imports
#include <string>

// portable filesystem by operating system
#include <filesystem>
#ifdef _WIN32
#include <windows.h>
#else
#include <unistd.h>
#endif

class Utils {
private:
    static const unsigned MAX_PATH = 260;

public:
    static std::string getExecutableDirectory();
};

#endif