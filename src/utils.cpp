#include "utils.h"

// this function gets the executable directory path in linux/windows systems
// sourced from: https://stackoverflow.com/questions/50889647/best-way-to-get-exe-folder-path#:~:text=%23include%20%3Cfilesystem,back)slash%0A%7D
std::string Utils::getExecutableDirectory() {
    #ifdef _WIN32
        // Windows specific
        wchar_t szPath[Utils::MAX_PATH];
        GetModuleFileNameW( NULL, szPath, Utils::MAX_PATH );
    #else
        // Linux specific
        char szPath[Utils::MAX_PATH];
        ssize_t count = readlink( "/proc/self/exe", szPath, Utils::MAX_PATH );
        if( count < 0 || count >= Utils::MAX_PATH )
            return {}; // some error
        szPath[count] = '\0';
    #endif
        return std::filesystem::path{ szPath }.parent_path() / ""; // to finish the folder path with (back)slash
}