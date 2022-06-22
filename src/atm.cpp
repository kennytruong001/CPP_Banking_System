#include <iostream>
#include <string>
#include <set>
#include <map>
using namespace std;

int main() {
  int input;
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


  cout << "1. Deposit" << endl;
  cout << "2. Withdraw" << endl;
  cout << "3. Check Balance" << endl;
  cin >> input;
}