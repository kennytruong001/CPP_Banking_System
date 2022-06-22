#include <iostream>
#include <string>
#include <set>
#include <map>
using namespace std;

int main() {
  int input;
  int bal = 0;
  bool active = true;
  int diff;

  string username = "";
  string password = ""; 
  map<string, string> login = {
    {"kenny", "pw1"},
    {"richard", "pw2"}
  };
  

  // loop for login user
  bool invalid_login = true;
  while (invalid_login) {
    cout << "Please enter your username: ";
    cin >> username;
    cout << "Please enter your password: ";
    cin >> password;

    if (login[username] == password) {
      cout << "Welcome back " << username << "!" << endl;
      break;
    }

    cout << "Sorry, incorrect username or password! Please try again" << endl;
  }
  
  while (active){
    cout << "1. Deposit" << endl;
    cout << "2. Withdraw" << endl;
    cout << "3. Check Balance" << endl;
    cout << "4. Exit" << endl;
    cin >> input;

    if (input == 1){
      cout << "How much would you like to deposit?: ";
      cin >> diff;
      bal += diff;
    }
    else if (input == 2){
      cout << "How much would you like to withdraw?: ";
      cin >> diff;
      bal -= diff;
    }

    else if (input == 3){
      cout << "Current balance: " << bal << endl; 
    }

    else if (input == 4){
      cout << "Thank you, have a nice day!" << endl; 
      active = false;
    }

    else{
      cout << "Invalid input, try again" << endl;
      
      cin.clear();
      cin.ignore();
    }
      

  }

}
