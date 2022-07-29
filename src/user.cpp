#include "user.h"

//USER CLASS
User::User() {
    name="Jane Doe";
    pass="password";
    email="user@domain.com";
    phone_number="##########";
}

User::User(std::string name, std::string pass, std::string email, std::string phone_number):name(name), pass(pass), email(email), phone_number(phone_number){}

User::User(const User &other){
	name = other.name;
	pass = other.pass;
    email = other.email;
    phone_number = other.phone_number;

}

// User& User::operator= (const User &user){
//     name = user.name;
//     pass = user.pass;
//     bal = user.bal;
// }

std::string User::getName(){
    return name;
}

std::string User::getPass(){
    return pass;
}


//CUSTOMER CLASS
Customer::Customer() {
    name="Jane Doe";
    pass="password";
    email="user@domain.com";
    phone_number="##########";
    accounts = {};
}

//Customer::Customer(std::string name, std::string pass, std::string email, std::string phone_number, std::map<std::string, float> accounts):accounts(accounts){}

Customer::Customer(const Customer &other){
	accounts = other.accounts;

}
void Customer::setName(std::string input){
    name = input;
}

void Customer::setPass(std::string input){
    pass = input;
}

std::map<std::string, float> Customer::getAccounts(){
    return accounts;
}

void Customer::setAccountsBal(std::string accountName, float amount, int action){
    if (action == 0) { //deposit
        accounts[accountName] += amount;
    }
    
    if (action == 1) { //withdraw
        accounts[accountName] -= amount;
    }
}
void Customer::transfer(std::string accountFrom, std::string accountTo, float amount){
    accounts[accountFrom] -= amount;
    accounts[accountTo] += amount;
}


//MANAGER CLASS
Manager::Manager() {
    name="Jane Doe";
    pass="password";
    email="user@domain.com";
    phone_number="##########";
    branch = "Scranton";
}

//Manager::Manager(std::string name, std::string pass, std::string email, std::string phone_number, std::string branch):branch(branch){}

Manager::Manager(const Manager &other){
    branch = other.branch;
}

void Manager::createUser(std::string name){
    std::cout<<"Created" + name << std::endl;
}
void Manager::deleteUser(std::string name){
    std::cout<<"Deleted" + name << std::endl;
}
std::string Manager::getBranch() {
    return branch;
}