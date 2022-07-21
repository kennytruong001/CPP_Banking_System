/**
 * @file display.h
 *
 * @brief This is a static function class that displays text prompts for the banking system
 *
 * @author Richard Duong & Kenny Truong
 */
#include "display.h"

void Display::menu(const std::string& name) {
  std::cout << std::endl;
  std::cout << "1. Deposit" << std::endl;
  std::cout << "2. Withdraw" << std::endl;
  std::cout << "3. Check Balance" << std::endl;
  std::cout << "4. Exit" << std::endl;
  std::cout << name << ", choose an option above: "; 
}

void Display::main() {
  std::cout<<"----------------------------------------- "<<std::endl;
  std::cout<<" W E L C O M E   T O   R D K T   B A N K " <<std::endl;
  std::cout<<"----------------------------------------- "<<std::endl;
  std::cout<<""<<std::endl;
  std::cout<<"What would you like to do today?"<<std::endl;
  std::cout<<"1. Log in"<<std::endl;
  std::cout<<"2. Create new user"<<std::endl;
}