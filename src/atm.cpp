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
	std::string saveFileName = Utils::getExecutableDirectory() + "..\\data\\records.txt";
	std::cout << "records.txt path is: " << saveFileName << std::endl;
	std::cout << "canonical records.txt path is at: " << Utils::getCanonicalPath(saveFileName) << std:: endl;

	int input;
	bool active = true;
	int diff;
	std::vector<std::string> userRecord_arr;
	size_t pos = 0;
	std::string token;
	std::string delimiter = ",";

	std::string username = "";
	std::string password = "";
	std::map<std::string, std::string> login = {
		{"kenny", "pw1"},
		{"richard", "pw2"}};

	std::map<std::string,User> userRecord = {};

	// READ file that has user info and stores it in a UserRecord hashmap
	std::fstream file;
	User userInstance[5];
	file.open("data/record.txt", std::ios::in);
	std::string line;
	int part_count = 0;
	int user_count = 0;
	std::string name = "";
	std::string pass = "";
	std::string pass_check = "";
	int bal = 0; 
	if (file.is_open()){
		while(std::getline(file,line)){

			userRecord_arr.push_back(line);

			while ((pos = line.find(delimiter)) != std::string::npos) {
    			token = line.substr(0, pos);
				if (part_count % 3 == 0){
					name = token;
				}
				else if (part_count % 3 == 1) {
					pass = token;
				}
				else if (part_count % 3 == 2) {
					bal = atoi(token.c_str());
				}

				part_count += 1;
    			line.erase(0, pos + delimiter.length());
			}

			userInstance[user_count].setName(name);
			userInstance[user_count].setPass(pass);
			userInstance[user_count].setBal(bal,0);
			user_count += 1;
		}
	}

	for (int i = 0; i<5;i++){
		userRecord.insert(std::pair<std::string, User>(userInstance[i].getName(), userInstance[i]) );
	}
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

			if (sha256(password) == userRecord[username].getPass()){
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
				userRecord.insert(std::pair<std::string, User>(username, User(username,sha256(pass), 0)));
				system("clear");
				file.open("record.txt", std::ios::app);
				if (file.is_open()) {
					file << "" <<std::endl;
					file << username << "," << sha256(pass) << ",0," <<std::endl;
				}
				std::cout << "Welcome " << username << "!" << std::endl;
				break;
			}
			else{
				std::cout<<"Password did not match, please try again"<<std::endl;
			}
		}
	}

	while (active)
	{
		Display::menu(userRecord[username].getName());
		std::cin >> input;
		system("clear");
		if (input == 1)
		{
			std::cout << "How much would you like to deposit?: ";
			std::cin >> diff;
			userRecord[username].setBal(diff, 0);
		}
		else if (input == 2)
		{
			std::cout << "How much would you like to withdraw?: ";
			std::cin >> diff;
			userRecord[username].setBal(diff, 1);
		}

		else if (input == 3)
		{
			std::cout << "Current balance: " << userRecord[username].getBal() << std::endl;
		}

		else if (input == 4)
		{
			std::cout << "Thank you, have a nice day!" << std::endl;
			active = false;
		}

		else
		{
			std::cout << "Invalid input, try again" << std::endl;
			std::cin.clear();
			std::cin.ignore();
		}
	}
	file.close();

}
