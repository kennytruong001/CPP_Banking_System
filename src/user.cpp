#include "user.h"

std::string User::getName(){
    return User::name;
}

void User::setName(std::string input){
    User::name = input;
}

std::string User::getPass(){
    return User::pass;
}

void User::setPass(std::string input){
    User::pass = input;
}

float User::getBal(){
    return User::bal;
}

void User::setBal(float amount, int action){
    if (action == 0){
        User::bal += amount;
    }

    if (action == 1){
        User::bal -= amount;
    }
}