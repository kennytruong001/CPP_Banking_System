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

class User {
protected:
	std::string name;
	std::string pass;
	std::string email;
	std::string phone_number;
	
public:
	User();
	User(const User &other);
	User(std::string name, std::string pass, std::string email, std::string phone_number);
	std::string getName();
	//void setName(std::string input);
	std::string getPass();
	//void setPass(std::string input);
	//float getBal();
	//void setBal(float amount, int action);

};

class Customer:public User {
protected:
	std::map<std::string,float> accounts;
public:
	Customer();
	Customer(const Customer &other);
	Customer(std::string name, std::string pass, std::string email, std::string phone_number, std::map<std::string,float> accounts):User(name, pass, email, phone_number){
		accounts = accounts;
	};
	void setName(std::string input);
	void setPass(std::string input);
	std::map<std::string,float> getAccounts();
	void setAccountsBal(std::string accountName, float amount, int action);
	void transfer(std::string accountFrom, std::string accountTo, float amount);
};

class Manager:public User {
private:
	std::string branch;

public:
	Manager();
	Manager(const Manager &other);
	Manager(std::string name, std::string pass, std::string email, std::string phone_number, std::string branch):User(name, pass, email, phone_number){
		branch = branch;
	}
	void createUser(std::string name);
	void deleteUser(std::string name);
	std::string getBranch();
};
#endif