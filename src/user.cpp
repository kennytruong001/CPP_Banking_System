#include "user.h"

//USER CLASS
User::User():
    type(CUSTOMER),
    name("Jane Doe"),
    pass("password"),
    email("user@domain.com"),
    phone_number("##########"){}

User::User(const Type type, const std::string name, const std::string pass, const std::string email, const std::string phone_number):
    type(type),
    name(name), 
    pass(pass), 
    email(email), 
    phone_number(phone_number){}

User::User(const User &other):
    type(other.type),
	name(other.name),
	pass(other.pass),
    email(other.email),
    phone_number(other.phone_number){}


// User& User::operator= (const User &user){
//     name = user.name;
//     pass = user.pass;
//     bal = user.bal;
// }


Type User::getType() {
    return type;
}

std::string User::getName(){
    return name;
}

std::string User::getPass(){
    return pass;
}

std::string User::getEmail(){
    return email;
}

std::string User::getPhoneNumber(){
    return phone_number;
}


