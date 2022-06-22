#include <iostream>
using namespace std;

int main() {
  int input;
  int bal = 0;
  bool active = true;
  int diff;

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
