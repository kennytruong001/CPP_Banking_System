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
#include <map>

enum Type{CUSTOMER, MANAGER};
Type parseType(std::string type);

class User {
protected:
	Type type;
	std::string name;
	std::string pass;
	std::string email;
	std::string phone_number;
	
public:
	User();
	User(const User &other);
	User(const Type type, const std::string name, const std::string pass, const std::string email, const std::string phone_number);
	//User* User::parseUserFromString(std::string type_str, std::string string);
	Type getType();
	std::string getName();
	//void setName(std::string input);
	std::string getPass();
	std::string getEmail();
	std::string getPhoneNumber();
	//void setPass(std::string input);
	//float getBal();
	//void setBal(float amount, int action);

};

#endif