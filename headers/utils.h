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
#include <windows.h>
#include <shlwapi.h>

class Utils {
public:
    static std::string getCanonicalPath(const std::string path);
    static std::string getExecutableDirectory();
    //void Parse(std::string stringParse, std::string delimiter);
};

#endif