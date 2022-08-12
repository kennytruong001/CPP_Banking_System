#include "../headers/utils.h"
#include <iostream>

// Sourced from: https://stackoverflow.com/questions/36685847/c-get-full-path-to-file-in-directory
std::string Utils::getCanonicalPath(const std::string path) {
    char source[MAX_PATH];
    char result[MAX_PATH];
    strcpy(source, path.c_str());
    PathCanonicalize(result, source); 
    //GetFullPathName(path.c_str(), MAX_PATH, fullFilename, nullptr);
    return std::string(result);
}

// Sourced from: https://gist.github.com/karolisjan/f9b8ac3ae2d41ec0ce70f2feac6bdfaf
std::string Utils::getExecutableDirectory() {
    char buffer[MAX_PATH];
	GetModuleFileNameA(NULL, buffer, MAX_PATH);
	std::string::size_type pos = std::string(buffer).find_last_of("\\/");	
	return std::string(buffer).substr(0, pos) + "\\";
}

Type parseType(std::string string){
    if (string == "C") return Type::CUSTOMER;
    if (string == "M") return Type::MANAGER;
}

User* Utils::parseUserFromString(const std::string type_str, const std::string attribute_str){
    Type type = parseType(type_str);
    switch(type){
        case CUSTOMER:
            return Customer::buildCustomerFromUserInfo(attribute_str);
            break;
        case MANAGER:
            return Manager::buildManagerFromUserInfo(attribute_str);
            break;
        default:
            throw "parseUserFromString() -> Unknown User Error";
    }
    return nullptr;
        
}

// void Utils::Parse(std::string stringParse, std::string delimiter) {

// }
