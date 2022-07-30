#include "user.h"

//USER CLASS
User::User():
    name("Jane Doe"),
    pass("password"),
    email("user@domain.com"),
    phone_number("##########"){}

// just nicer styling for initializer list
User::User(std::string name, std::string pass, std::string email, std::string phone_number):
    name(name),
    pass(pass),
    email(email),
    phone_number(phone_number){}

User::User(const User &other):
    name(other.name),
    pass(other.pass),
    email(other.email),
    phone_number(other.phone_number){}

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
// here we can use the initializer list to instantiate our base class User
Customer::Customer():
    User::User(
        "Jane Doe",
        "password",
        "user@domain.com",
        "##########"),
    // for accounts, this calls the default constructor of the accounts map***
    accounts(){}

// NOTE: when you initialize a customer, you still need to instantiate the User base class underneath
Customer::Customer(std::string name, std::string pass, std::string email, std::string phone_number, std::map<std::string, float> accounts):
    User::User(
        name,
        pass,
        email,
        phone_number),
    accounts(accounts){}

Customer::Customer(const Customer &other):
    User::User(
        other.name,
        other.pass,
        other.email,
        other.phone_number),
    accounts(other.accounts){}

void Customer::setName(std::string input){
    name = input;
}

void Customer::setPass(std::string input){
    pass = input;
}

std::map<std::string, float> Customer::getAccounts(){
    return accounts;
}

// NOTE: this function is doing too many jobs at once!
// make it so that it only adds to the balance or subtracts from the balance
// actions need to be handled by the ATM, not the Customer class
void Customer::setAccountsBal(std::string accountName, float amount, int action){
    if (action == 0) { //deposit
        accounts[accountName] += amount;
    }
    
    if (action == 1) { //withdraw
        accounts[accountName] -= amount;
    }
}

// we need some checks here, what if the transfer amount is illegal?
// i.e. accountFrom is trying to deduct more money than it actually has
void Customer::transfer(std::string accountFrom, std::string accountTo, float amount){
    accounts[accountFrom] -= amount;
    accounts[accountTo] += amount;
}


//MANAGER CLASS
// take a look at what I did for customer class and do it here
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