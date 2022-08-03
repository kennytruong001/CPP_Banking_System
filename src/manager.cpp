#include "manager.h"

//MANAGER CLASS
Manager::Manager():
    User::User(
        "Jane Doe",
        "password",
        "user@domain.com",
        "##########"),
    branch(){}


Manager::Manager(const std::string name, const std::string pass, const std::string email, const std::string phone_number, const std::string branch):
    User::User(
        name, 
        pass, 
        email, 
        phone_number),
    branch(branch){}

Manager::Manager(const Manager &other):
    User::User(
        name,
        pass,
        email,
        phone_number),
    branch(other.branch){}

void Manager::createUser(const std::string name){
    std::cout<<"Created" + name << std::endl;
}
void Manager::deleteUser(const std::string name){
    std::cout<<"Deleted" + name << std::endl;
}
std::string Manager::getBranch() {
    return branch;
}