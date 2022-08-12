#ifndef MANAGER_H
#define MANAGER_H

// standard libraries
#include <iostream>
#include <string>
#include <sstream>
#include "user.h"

class Manager:public User {
private:
	std::string branch;

public:
	Manager();
	Manager(const Manager &other);
	Manager(const Type type, const std::string name, const std::string pass, const std::string email, const std::string phone_number, const std::string branch);
	static Manager* buildManagerFromUserInfo (std::string userInfo);
	void createUser(const std::string name);
	void deleteUser(const std::string name);
	std::string getBranch();
};

#endif