/**
 * @file user.h
 *
 * @brief This is a static function class that displays text prompts for the banking system
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
	static std::string name;
	static std::string pass;
	static int bal;

public:
	// User();
	// User(const User &other);
	User(std::string name, std::string pass, int bal);
	static std::string getName();
	static void setName(std::string input);
	static std::string getPass();
	static void setPass(std::string input);
	static float getBal();
	static void setBal(float amount, int action);
};

// User::User(){
// 	name = "";
// 	pass = "";
// 	bal = 0;
// }
// User::User(const User &other){
// 	name = other.name;
// 	pass = other.pass;
// 	bal = other.bal;
// }
User::User(std::string name, std::string pass, int bal){
	name=name; 
	pass=pass; 
	bal=bal;
}

#endif