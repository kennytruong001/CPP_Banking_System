#include "user.h"

User::User() {
    name="Jane Doe";
    pass="password";
    bal=0;
}

User::User(std::string name, std::string pass, int bal):name(name), pass(pass), bal(bal){}

User::User(const User &other){
	name = other.name;
	pass = other.pass;
	bal = other.bal;
}

// User& User::operator= (const User &user){
//     name = user.name;
//     pass = user.pass;
//     bal = user.bal;
// }

std::string User::getName(){
    return name;
}

void User::setName(std::string input){
    name = input;
}

std::string User::getPass(){
    return pass;
}

void User::setPass(std::string input){
    pass = input;
}

float User::getBal(){
    return bal;
}

void User::setBal(float amount, int action){
    if (action == 0){
        bal += amount;
    }

    if (action == 1){
        bal -= amount;
    }
}