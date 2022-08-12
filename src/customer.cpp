#include "customer.h"

//CUSTOMER CLASS
Customer::Customer():
    User::User(
        Type::CUSTOMER,
        "Jane Doe", 
        "password",
        "user@domain.com",
        "##########"),
        accounts(){}

Customer::Customer(const Type type, const std::string name, const std::string pass, const std::string email, const std::string phone_number, std::map<std::string, float> accounts):
    User::User(
        type,
        name, 
        pass, 
        email, 
        phone_number),
    accounts(accounts){}

Customer::Customer(const Customer &other):
	User::User(
        other.type,
        other.name,
        other.pass,
        other.email,
        other.phone_number),
    accounts(other.accounts){}

Customer* Customer::buildCustomerFromUserInfo(std::string userInfo){
    std::stringstream ss(userInfo);
    std::string name;
    std::string pass;
    std::string email;
    std::string phone_number;
    std::map<std::string,float> accounts;

    //parse
    ss >> name >> pass >> email >> phone_number;
    while (ss.rdbuf()->in_avail() != 0) {
        std::string accountName, bal;
        //float bal;
        ss >> accountName >> bal;
        accounts.insert(std::pair<std::string, float>(accountName, stof(bal)));
    }
    return new Customer(Type::CUSTOMER, name, pass, email, phone_number, accounts);
}

void Customer::setName(const std::string input){
    name = input;
}

void Customer::setPass(const std::string input){
    pass = input;
}

void Customer::getAccounts(){
    std::cout << "Here is the balance of your accounts" << std::endl;
    for (std::map<std::string, float>::iterator it = accounts.begin(); it != accounts.end(); ++it){
        std::cout << it->first << ":" << std::to_string(it->second) << ";";
    }
}

void Customer::deposit(const std::string accountName, const float amount){
    accounts[accountName] += amount;
    std::cout << "You deposit $" << std::to_string(amount) << " from " << accountName <<"!" << std::endl;
}

void Customer::withdraw(const std::string accountName, const float amount){
    if (amount > accounts[accountName]){
        std::cout << "Withdrawal amount is more than account balance!" << std::endl;
        std::cout << "Account balance is: $" << std::to_string(accounts[accountName]) << std::endl;
    }
    else{
        accounts[accountName] -= amount;
        std::cout << "You withdrew $" << std::to_string(amount) << " from " << accountName <<"!" << std::endl;
    }
}

void Customer::transfer(const std::string accountFrom, const std::string accountTo, const float amount){
    if (amount > accounts[accountFrom]){
        std::cout << "Transfer amount is more than account balance!" << std::endl;
        std::cout << "Account balance is: $" << std::to_string(accounts[accountFrom]) << std::endl;
    }
    else{
        accounts[accountFrom] -= amount;
        accounts[accountTo] += amount;
        std::cout << "You transfered $" << std::to_string(amount) << " from " << accountFrom <<" to " << accountTo << "!" << std::endl;
    }
    
}

std::map<std::string,float> Customer::getOnlyAccount(){
    return accounts;
}