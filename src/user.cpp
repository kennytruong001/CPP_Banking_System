#include "user.h"

//USER CLASS
User::User():
    name("Jane Doe"),
    pass("password"),
    email("user@domain.com"),
    phone_number("##########"){}

User::User(const std::string name, const std::string pass, const std::string email, const std::string phone_number):
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


