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
# include "utils.h"

int main()
{

	// please remove me after you get it working!
	std::string saveFileName = Utils::getExecutableDirectory() + "..\\data\\records.txt";
	std::cout << "records.txt path is: " << saveFileName << std::endl;
	std::cout << "canonical records.txt path is at: " << Utils::getCanonicalPath(saveFileName) << std:: endl;

	int input;
	//int bal = 0;
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

	//User kenny("kenny", "pw1", 1000);
	//User richard("richard", "pw2", 0);

	// std::map<std::string, User> userRecord = {
	// 	{"kenny", kenny},
	// 	{"richard", richard}
	// };
	std::map<std::string,User> userRecord = {};

	// READ and WRITE file that has user info
	std::fstream file;
	User userInstance[5];
	file.open("data/record.txt", std::ios::in);
	std::string line;
	int part_count = 0;
	int user_count = 0;
	std::string name = "";
	std::string pass = "";
	int bal = 0; 
	if (file.is_open()){
		while(std::getline(file,line)){
			//std::cout << line << std::endl;
			userRecord_arr.push_back(line);

			while ((pos = line.find(delimiter)) != std::string::npos) {
    			token = line.substr(0, pos);
				if (part_count % 3 == 0){
					name = token;
					//std::cout<<name<<std::endl;
				}
				else if (part_count % 3 == 1) {
					pass = token;
					//std::cout<<pass<<std::endl;
				}
				else if (part_count % 3 == 2) {
					//bal = std::stoi(token);
					bal = atoi(token.c_str());
					//std::cout<<bal<<std::endl;
				}
				//User name(name,pass,bal);
				part_count += 1;
    			//std::cout << token << std::endl;
    			line.erase(0, pos + delimiter.length());
				
			}

			userInstance[user_count].setName(name);
			userInstance[user_count].setPass(pass);
			userInstance[user_count].setBal(bal,0);
			user_count += 1;
		}
	}

	for (int i = 0; i<5;i++){
		// std::cout<<userInstance[i].getName()<<std::endl;
		// std::cout<<userInstance[i].getPass()<<std::endl;
		// std::cout<<userInstance[i].getBal()<<std::endl;
		userRecord.insert(std::pair<std::string, User>(userInstance[i].getName(), userInstance[i]) );
	}
	// char word[] = "pw1";
	// std::string sha256_pass = SHA256(word);
	// std::cout<<"pw1: "<< sha256_pass << std::endl;
	// char word2[] = "pw2";
	// sha256_pass = SHA256(word2);
	// std::cout<<"pw2: "<< sha256_pass << std::endl;


	//std::cout<<line<<std::endl;
	// loop for login user
	bool invalid_login = true;
	while (invalid_login)
	{
		std::cout << "Please enter your username: ";
		std::cin >> username;
		std::cout << "Please enter your password: ";
		std::cin >> password;

		if (sha256(password) == userRecord[username].getPass()){
			std::cout << "Welcome back " << username << "!" << std::endl;
			break;
		}

		// if (login[username] == password)
		// {
		// 	std::cout << "Welcome back " << username << "!" << std::endl;
		// 	break;
		// }

		std::cout << "Sorry, incorrect username or password! Please try again" << std::endl;
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
			//bal += diff;
			userRecord[username].setBal(diff, 0);
		}
		else if (input == 2)
		{
			std::cout << "How much would you like to withdraw?: ";
			std::cin >> diff;
			//bal -= diff;
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
