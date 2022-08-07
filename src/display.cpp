/**
 * @file display.h
 *
 * @brief This is a static function class that displays text prompts for the banking system
 *
 * @author Richard Duong & Kenny Truong
 */
#include "display.h"

void Display::customerMenu(const std::string& name) {
  std::cout << std::endl;
  std::cout << "1. Deposit" << std::endl;
  std::cout << "2. Withdraw" << std::endl;
  std::cout << "3. Transfer" << std::endl;
  std::cout << "4. Check Balance" << std::endl;
  std::cout << "5. Exit" << std::endl;
  std::cout << name << ", choose an option above: "; 
}

void Display::managerMenu(const std::string& name) {
  std::cout << std::endl;
  std::cout << "1. Create a user" << std::endl;
  std::cout << "2. Delete a user" << std::endl;
  std::cout << "3. Exit" << std::endl;
  std::cout << name << ", choose an option above: "; 
}

void Display::main() {
  std::cout<<"----------------------------------------- "<<std::endl;
  std::cout<<" W E L C O M E   T O   R D K T   B A N K " <<std::endl;
  std::cout<<"----------------------------------------- "<<std::endl;
  std::cout<<""<<std::endl;
  std::cout<<"Please log into your account"<<std::endl;

  //std::cout<<"2. Create new user"<<std::endl;
}

void Display::accountMenu() {
  std::cout<<"1. Checking" << std::endl;
  std::cout<<"2. Savings" << std::endl;
  std::cout<<"3. Custom" << std::endl;
}