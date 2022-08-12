// standard libraries
#include <iostream>
#include <string>
#include <set>
#include <map>
#include <fstream>
#include <vector>
#include <sstream>
#include <typeinfo>

// custom libraries
#include "display.h"
#include "user.h"
#include "customer.h"
#include "manager.h"
#include "sha256.h"
#include "../headers/utils.h"

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
	//size_t pos = 0;
	std::string token;
	std::string tokenAccount;
	std::string type;
	std::string account;
	std::string accountName;
	//float accountBal;
	std::string delimiter = "|";

	std::string username = "";
	std::string password = "";

	std::vector<User*> userList;
	std::map<std::string,User*> userRecord = {};

	// READ file that has user info and stores it in a UserRecord hashmap
	std::fstream file;

	file.open("data/record.txt", std::ios::in);
	std::string line;
	//int part_count = 0;
	//int bal_part = 0;
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

	// if (file.is_open()){
	// 	while(std::getline(file,line)){
	// 		std::stringstream ss(line);
	// 		while (ss.good()){
	// 			std::string substr;
	// 			getline(ss, substr, '|');
	// 			userRecord_arr.push_back(substr);
	// 		}
	// 	}
	// }

	// for (int i = 0; i < signed(userRecord_arr.size()); i+=2){
	// 	if (userRecord_arr[i] =="C"){
	// 		type = "C";
	// 		std::stringstream str_line(userRecord_arr[i+1]);

	// 		//USER INFO: NAME, PASSWORD, EMAIL, PHONE_NUMBER, ACCOUNTS
	// 		while (str_line.good()){
	// 			std::string substr;
	// 			getline(str_line, substr, ',');
	// 			if (part_count % 5 == 0){
	// 				name = substr;
	// 				//std::cout << "NAME: " << name << std::endl;
	// 			}
	// 			else if (part_count % 5 == 1){
	// 				pass = substr;
	// 				//std::cout << "PASS: " << pass << std::endl;
	// 			}
	// 			else if (part_count % 5 == 2){
	// 				email = substr;
	// 				//std::cout << "EMAIL: " << email << std::endl;
	// 			}
	// 			else if (part_count % 5 == 3){
	// 				phone_number = substr;
	// 				//std::cout << "PHONE NUMBER: " << phone_number << std::endl;
	// 			}
	// 			else if (part_count % 5 == 4){
	// 				accountsString = substr;

	// 				std::stringstream account_line(accountsString);
	// 				std::cout << "ACCOUNT>>" << accountsString <<std::endl;
	// 				//STRING OF ACCOUNTS
	// 				while (account_line.good()){
	// 					std::string account_substr;
	// 					getline(account_line, account_substr, ';');
			
	// 					//ACCOUNT NAME : BALANCE
	// 					std::stringstream bal_line(account_substr);
	// 					while (bal_line.good()){
	// 						std::string bal_substr;
	// 						getline(bal_line, bal_substr, ':');
	// 						std::cout << "BAL_PART" << std::to_string(bal_part) << "---" << bal_substr << "---" << account_substr<<std::endl;
	// 						if (bal_part % 2 == 0){
	// 							accountName = bal_substr;
	// 							//std::cout << "ACCOUNT NAME: " << accountName << std::endl;
	// 						}
	// 						if (bal_part % 2 == 1){
	// 							accountBal = stof(bal_substr);
	// 							//std::cout << "BALANCE: " << bal_substr << std::endl;
	// 						}
	// 						accounts.insert(std::pair<std::string,float>(accountName, accountBal));
	// 						bal_part++;
	// 					}
	// 				}
	// 			}
	// 			part_count++;
	// 		}
	// 		userList.push_back(new Customer(type, name, pass, email, phone_number, accounts));
	// 	}
	// 	else if (userRecord_arr[i] == "M"){
	// 		type = "M";
	// 		std::stringstream str_line(userRecord_arr[i+1]);

	// 		//USER INFO: NAME, PASSWORD, EMAIL, PHONE_NUMBER, ACCOUNTS
	// 		while (str_line.good()){
	// 			std::string substr;
	// 			getline(str_line, substr, ',');
	// 			if (part_count % 5 == 0){
	// 				name = substr;
	// 			}
	// 			else if (part_count % 5 == 1){
	// 				pass = substr;
	// 			}
	// 			else if (part_count % 5 == 2){
	// 				email = substr;
	// 			}
	// 			else if (part_count % 5 == 3){
	// 				phone_number = substr;
	// 			}
	// 			else if (part_count % 5 == 4){
	// 				branch = substr;
	// 				//std::cout << "BRANCH: " << branch << std::endl;
	// 			}
	// 			part_count++;
	// 		}
	// 		userList.push_back(new Manager(type, name, pass, email, phone_number, branch));
	// 	}
	// }
	
	//file.open("record.txt", std::ios::in);
	if (!file.is_open()){
		throw "record.txt could not be opened";
	}
	
	std::string type_str, attribute_str;
	while(file >> type_str){
		std::cout<<"TYPE_STR: "<< type_str << std::endl;
		getline(file, attribute_str);
		std::cout<<"ATTRIBUTE_STR: "<< attribute_str << std::endl;
		User* user = Utils::parseUserFromString(type_str, attribute_str);
		userList.push_back(user);
	}
	std::cout<<"USERLIST_SIZE: "<< userList.size() << std::endl;


	for (int i=0; i < signed(userList.size()); i++){
		std::string name = userList[i]->getName();
		std::cout<<"NAME: "<< userList[i]->getName() << std::endl;
		userRecord.insert(std::pair<std::string, User*>(name, userList[i]));
	}

	file.close();

	// loop for login user
	bool invalid_login = true;
	while (invalid_login)
	{
		Display::main();
		//std::cin>>input;
		std::cout << "Please enter your username: ";
		std::cin >> username;
		std::cout << "Please enter your password: ";
		std::cin >> password;
		std::cout<<"GETS HERE AND SEE " << std::endl;
		if (sha256(password) == userRecord[username]->getPass()){
			std::cout << "Welcome back " << username << "!" << std::endl;
			break;
		}
		else{
			std::cout << "Sorry, incorrect username or password! Please try again" << std::endl;
		}
	}		
									// //Create a user
									// if (input == 2) {
									// 	std::cout<<"What username would you like? " <<std::endl;
									// 	std::cin>>username;
									// 	std::cout<<"What password would you like? " <<std::endl;
									// 	std::cin>>pass;
									// 	std::cout<< "Retype the password" <<std::endl;
									// 	std::cin>>pass_check;

									// 	if (pass.compare(pass_check) == 0) {
									// 		if (userRecord.count(username) == 0){
									// 			//userRecord.insert(std::pair<std::string, User>(username, User(username,sha256(pass), 0)));
									// 			std::fstream myfile;
									// 			system("clear");
									// 			myfile.open("data/record.txt", std::ios::app);
									// 			if (myfile.is_open()) {
									// 				myfile << "" <<std::endl;
									// 				myfile << username << "," << sha256(pass) << ",0," <<std::endl;
									// 			}
									// 			std::cout << "Welcome " << username << "!" << std::endl;
									// 			break;
									// 		}

									// 		else {
									// 			std::cout<<""<<std::endl;
									// 			std::cout<< "User already exists!" <<std::endl;
									// 			std::cout<<""<<std::endl;
									// 		}
									// 		//Needs to check if user is already created
									// 		//makes more room in userRecord if # of users > 5

									// 	}
									// 	else{
									// 		std::cout<<"Password did not match, please try again"<<std::endl;
									// 	}
									// }
	

	if (userRecord[username]->getType() == CUSTOMER){
		while (active) {
			Display::customerMenu(userRecord[username]->getName());
			std::cin >> input;
			//system("clear");
			Customer* customer = static_cast<Customer*>(userRecord[username]);
			switch(input) {
			case 1:
				std::cout << "What account would you like to deposit to?: ";
				std::cin >> accountName;
				std::cout << "How much would you like to deposit?: ";
				std::cin >> diff;
				customer->deposit(accountName, diff);
				break;
			case 2:
			std::cout << "What account would you like to withdraw from?: ";
				std::cin >> accountName;
				std::cout << "How much would you like to withdraw?: ";
				std::cin >> diff;
				customer->withdraw(accountName, diff);
				break;
			case 3:
				std::cout << "What account would you like to transfer money FROM: ";
				std::cin >> accountNameFrom;
				std::cout << "What account would you like to transfer money TO: ";
				std::cin >> accountNameTo;
				std::cout << "How much would you want to transfer: ";
				std::cin >> amount;
				customer->transfer(accountNameFrom, accountNameTo, amount);
			case 4:
				//std::cout << "Here are your accounts: " << customerRecord[username].getAccounts() << std::endl;
				customer->getAccounts();
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
	}
	else if (userRecord[username]->getType() == MANAGER){
		while(active){
			Display::managerMenu(userRecord[username]->getName());
			std::cin >> input;
			//system("clear");
			switch(input) {
				case 1:
					std::cout << "CREATE USER (placeholder)" << std::endl;
					break;
				case 2:
					std::cout << "DELETE USER (placeholder)" << std::endl;
					break;
				case 3:
					std::cout << "Thank you, have a nice day!" << std::endl;
					active = false;
					break;
				default:
					std::cout << "Invalid input, try again" << std::endl;
					std::cin.clear();
					std::cin.ignore();
			}
		}
	}


	//file.close();
	std::fstream myFile;
	
	myFile.open("data/record.txt", std::ios::out);
	for (std::map<std::string, User*>::iterator it = userRecord.begin(); it != userRecord.end(); ++it){
    	if (it->second->getType() == CUSTOMER){
			Customer* customer = static_cast<Customer*>(it->second);
			myFile << "C " << customer->getName() << " " << customer->getPass() << " " << customer->getEmail() << " " << customer->getPhoneNumber() << " ";
			for (std::map<std::string, float>::iterator it2 = customer->getOnlyAccount().begin(); it2 != customer->getOnlyAccount().end(); ++it2){
        		myFile << it2->first << " " << std::to_string(it2->second) << " ";
    		}
			myFile << std::endl;
		}
		else if (it->second->getType() == MANAGER){
			Manager* manager = static_cast<Manager*>(it->second);
			myFile << "M " << manager->getName() << " " << manager->getPass() << " " << manager->getEmail() << " " << manager->getPhoneNumber() << " " << manager->getBranch() << std::endl;
		}
    }
	myFile.close();
}
