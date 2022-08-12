#ifndef CUSTOMER_H
#define CUSTOMER_H

// standard libraries
#include <iostream>
#include <string>
#include <map>
#include <vector>
#include <sstream>
#include "user.h"

class Customer:public User {
protected:
	std::map<std::string,float> accounts;
public:
	Customer();
	Customer(const Customer &other);
	Customer(const Type type, const std::string name, const std::string pass, const std::string email, const std::string phone_number, std::map<std::string,float> accounts);
	static Customer* buildCustomerFromUserInfo(std::string userInfo);
	void setName(const std::string input);
	void setPass(const std::string input);
	void getAccounts();
	void deposit(const std::string accountName, const float amount);
	void withdraw(const std::string accountName, const float amount);
	void transfer(const std::string accountFrom, const std::string accountTo, const float amount);
    std::map<std::string,float> getOnlyAccount();
};

#endif