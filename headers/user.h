#ifndef USER_H
#define USER_H

#include <string>

class User {
private:
    std::string username;
    float balance;

public:
    User(std::string username, float balance);
    std::string getUsername();
    float getBalance();
};

#endif