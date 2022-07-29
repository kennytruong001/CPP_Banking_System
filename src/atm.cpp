// standard libraries
#include <iostream>
#include <string>
#include <set>
#include <map>
#include <fstream>
#include <vector>

// custom libraries
#include "display.h"
#include "user.h"
#include "sha256.h"
#include "utils.h"

int main()
{

	// please remove me after you get it working!
	// std::string saveFileName = Utils::getExecutableDirectory() + "..\\data\\records.txt";
	// std::cout << "records.txt path is: " << saveFileName << std::endl;
	// std::cout << "canonical records.txt path is at: " << Utils::getCanonicalPath(saveFileName) << std:: endl;

	int input;
	bool active = true;
	int diff;
	std::vector<std::string> userRecord_arr;
	size_t pos = 0;
	std::string token;
	std::string tokenAccount;
	std::string account;
	std::string accountName;
	float accountBal;
	std::string delimiter = ",";
	std::string accountsDelimiter = ";";
	std::string balDelimiter = ":";

	std::string username = "";
	std::string password = "";

	std::map<std::string,User> userRecord = {};
	std::map<std::string,Customer> customerRecord = {};
	std::map<std::string,Manager> managerRecord = {};

	// READ file that has user info and stores it in a UserRecord hashmap
	std::fstream file;
	std::vector<Customer*> customerList;
	std::vector<Manager*> managerList;
	file.open("data/record.txt", std::ios::in);
	std::string line;
	int part_count = 0;
	int account_part = 0;
	int bal_part = 0;
	int user_count = 0;
	std::string type = "";
	std::string name = "";
	std::string pass = "";
	std::string email = "";
	std::string phone_number = "";
	std::string pass_check = "";
	std::string accountsString = "";
	std::string branch = "";
	std::string accountNameFrom = "";
	std::string accountNameTo = "";
	float amount = 0.0;
	std::map<std::string,float> accounts = {};
	//int bal = 0;

	if (file.is_open()){
		while(std::getline(file,line)){

			userRecord_arr.push_back(line);

			while ((pos = line.find(delimiter)) != std::string::npos) {
    			token = line.substr(0, pos);
				if (part_count % 6 == 0){
					type = token;
				}
				else if (part_count % 6 == 1){
					name = token;
				}
				else if (part_count % 6 == 2) {
					pass = token;
				}
				else if (part_count % 6 == 3) {
					email =  token;
				}
				else if (part_count % 6 == 4) {
					phone_number = token;
				}
				else if (part_count % 6 == 5){
					if (type == "C"){
						accountsString = token;
						while ((pos = accountsString.find(accountsDelimiter)) != std::string::npos){
							account = accountsString.substr(0, pos);
							while ((pos = account.find(balDelimiter)) != std::string::npos){
								if (bal_part % 2 == 0){
									accountName = tokenAccount;
								}
								if (bal_part % 2 == 1){
									accountBal = stof(tokenAccount);
								}
							}
							account_part += 1;
							account.erase(0, pos + balDelimiter.length());
							accounts.insert(std::pair<std::string, float>(accountName, accountBal));
						}
						
						customerList.push_back(new Customer(name, pass, email, phone_number, accounts));
					}
					else if (type == "M"){
						branch = token;
						managerList.push_back(new Manager(name, pass, email, phone_number, branch));
					}
				}
				part_count += 1;
    			line.erase(0, pos + delimiter.length());
			}

			// userInstance[user_count].setName(name);
			// userInstance[user_count].setPass(pass);
			// userInstance[user_count].setBal(bal,0);
			
			user_count += 1;
		}
	}

	// for (int i = 0; i<5;i++){
	// 	userRecord.insert(std::pair<std::string, User>(userInstance[i].getName(), userInstance[i]) );
	// }
	for (int i=0; i < signed(customerList.size()); i++){
		customerRecord.insert(std::pair<std::string,Customer>(customerList[i]->getName(), *(customerList)[i]));
	}
	for (int i=0; i < signed(managerList.size()); i++){
		managerRecord.insert(std::pair<std::string,Manager>(managerList[i]->getName(), *(managerList)[i]));
	}
	std::cout<<managerRecord["kenny"].getName()<<std::endl;
	// char word[] = "pw1";
	// std::string sha256_pass = SHA256(word);
	// std::cout<<"pw1: "<< sha256_pass << std::endl;
	// char word2[] = "pw2";
	// sha256_pass = SHA256(word2);
	// std::cout<<"pw2: "<< sha256_pass << std::endl;

	// loop for login user
	bool invalid_login = true;
	while (invalid_login)
	{
		Display::main();
		std::cin>>input;
		if (input == 1){
			std::cout << "Please enter your username: ";
			std::cin >> username;
			std::cout << "Please enter your password: ";
			std::cin >> password;

			if (sha256(password) == customerRecord[username].getPass()){
				std::cout << "Welcome back " << username << "!" << std::endl;
				break;
			}

			else if (sha256(password) == managerRecord[username].getPass()){
				std::cout << "Welcome back " << username << "!" << std::endl;
				break;
			}
			std::cout << "Sorry, incorrect username or password! Please try again" << std::endl;
		}

		//Create a user
		if (input == 2) {
			std::cout<<"What username would you like? " <<std::endl;
			std::cin>>username;
			std::cout<<"What password would you like? " <<std::endl;
			std::cin>>pass;
			std::cout<< "Retype the password" <<std::endl;
			std::cin>>pass_check;

			if (pass.compare(pass_check) == 0) {
				if (userRecord.count(username) == 0){
					//userRecord.insert(std::pair<std::string, User>(username, User(username,sha256(pass), 0)));
					std::fstream myfile;
					system("clear");
					myfile.open("data/record.txt", std::ios::app);
					if (myfile.is_open()) {
						myfile << "" <<std::endl;
						myfile << username << "," << sha256(pass) << ",0," <<std::endl;
					}
					std::cout << "Welcome " << username << "!" << std::endl;
					break;
				}

				else {
					std::cout<<""<<std::endl;
					std::cout<< "User already exists!" <<std::endl;
					std::cout<<""<<std::endl;
				}
				//Needs to check if user is already created
				//makes more room in userRecord if # of users > 5

			}
			else{
				std::cout<<"Password did not match, please try again"<<std::endl;
			}
		}
	}

	while (active) {
		Display::menu(userRecord[username].getName());
		std::cin >> input;
		system("clear");
		// if (input == 1)
		// {
		// 	std::cout << "How much would you like to deposit?: ";
		// 	std::cin >> diff;
		// 	userRecord[username].setBal(diff, 0);
		// }
		// else if (input == 2)
		// {
		// 	std::cout << "How much would you like to withdraw?: ";
		// 	std::cin >> diff;
		// 	userRecord[username].setBal(diff, 1);
		// }

		// else if (input == 3)
		// {
		// 	std::cout << "Current balance: " << userRecord[username].getBal() << std::endl;
		// }

		// else if (input == 4)
		// {
		// 	std::cout << "Thank you, have a nice day!" << std::endl;
		// 	active = false;
		// }

		// else
		// {
		// 	std::cout << "Invalid input, try again" << std::endl;
		// 	std::cin.clear();
		// 	std::cin.ignore();
		// }
		switch(input) {
		case 1:
			std::cout << "What account would you like to deposit to?: ";
			std::cin >> accountName;
			std::cout << "How much would you like to deposit?: ";
			std::cin >> diff;
			customerRecord[username].setAccountsBal(accountName, diff, 0);
			break;
		case 2:
		std::cout << "What account would you like to withdraw from?: ";
			std::cin >> accountName;
			std::cout << "How much would you like to withdraw?: ";
			std::cin >> diff;
			customerRecord[username].setAccountsBal(accountName, diff, 1);
			break;
		case 3:
			std::cout << "What account would you like to transfer money FROM: ";
			std::cin >> accountNameFrom;
			std::cout << "What account would you like to transfer money TO: ";
			std::cin >> accountNameTo;
			std::cout << "How much would you want to transfer: ";
			std::cin >> amount;
			customerRecord[username].transfer(accountNameFrom, accountNameTo, amount);
		case 4:
			//std::cout << "Here are your accounts: " << customerRecord[username].getAccounts() << std::endl;
			std::cout<<"BALANCE"<<std::endl;
			break;
		case 5:
			std::cout << "Thank you, have a nice day!" << std::endl;
			active = false;
			break;
		default:
			std::cout << "Invalid input, try again" << std::endl;
			std::cin.clear();
			std::cin.ignore();
		}
	}

	

	file.close();

}
