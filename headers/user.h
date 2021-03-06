/**
 * @file user.h
 *
 * @brief This is a user class that keeps track of important details of users
 *
 * @author Richard Duong & Kenny Truong
 */
#ifndef USER_H
#define USER_H

// standard libraries
#include <iostream>
#include <string>

class User {
private:
	std::string name;
	std::string pass;
	int bal;

public:
	User();
	User(const User &other);
	User(std::string name, std::string pass, int bal);
	std::string getName();
	void setName(std::string input);
	std::string getPass();
	void setPass(std::string input);
	float getBal();
	void setBal(float amount, int action);
};

#endif