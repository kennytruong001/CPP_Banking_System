/**
 * @file display.h
 *
 * @brief This is a static function class that displays text prompts for the banking system
 *
 * @author Richard Duong & Kenny Truong
 */
#include "display.h"

void Display::menu(const std::string& name) {
  std::cout << "1. Deposit" << std::endl;
  std::cout << "2. Withdraw" << std::endl;
  std::cout << "3. Check Balance" << std::endl;
  std::cout << "4. Exit" << std::endl;
  std::cout << name << ", choose an option above: "; 
}