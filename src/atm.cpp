// standard libraries
#include <iostream>
#include <string>
#include <set>
#include <map>

// custom libraries
#include "display.h"
#include "user.h"

int main() {
  int input;
  int bal = 0;
  bool active = true;
  int diff;

  std::string username = "";
  std::string password = ""; 
  std::map<std::string, std::string> login = {
    {"kenny", "pw1"},
    {"richard", "pw2"}
  };
  

  // loop for login user
  bool invalid_login = true;
  while (invalid_login) {
    std::cout << "Please enter your username: ";
    std::cin >> username;
    std::cout << "Please enter your password: ";
    std::cin >> password;

    if (login[username] == password) {
      std::cout << "Welcome back " << username << "!" << std::endl;
      break;
    }

    std::cout << "Sorry, incorrect username or password! Please try again" << std::endl;
  }
  
  while (active){
    Display::menu(username);
    std::cin >> input;

    if (input == 1){
      std::cout << "How much would you like to deposit?: ";
      std::cin >> diff;
      bal += diff;
    }
    else if (input == 2){
      std::cout << "How much would you like to withdraw?: ";
      std::cin >> diff;
      bal -= diff;
    }

    else if (input == 3){
      std::cout << "Current balance: " << bal << std::endl; 
    }

    else if (input == 4){
      std::cout << "Thank you, have a nice day!" << std::endl; 
      active = false;
    }

    else{
      std::cout << "Invalid input, try again" << std::endl;    
      std::cin.clear();
      std::cin.ignore();
    }
  }
}
