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

int main()
{
	// // please remove me after you get it working!
	// std::string saveFileName = Utils::getExecutableDirectory() + "../data/records.txt";
	// std::cout << "records.txt directory is at: " << saveFileName << std::endl;
	std::cout<<"HELLO WORLD"<<std::endl;
	
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

	User kenny("kenny", "pw1", 1000);
	User richard("richard", "pw2", 0);

	std::map<std::string, User> userRecord = {
		{"kenny", kenny},
		{"richard", richard}
	};

	// READ and WRITE file that has user info
	std::fstream file;
	file.open("data/record.txt", std::ios::in);
	std::string line;
	if (file.is_open()){
		while(std::getline(file,line)){
			//std::cout << line << std::endl;
			userRecord_arr.push_back(line);
			while ((pos = line.find(delimiter)) != std::string::npos) {
    			token = line.substr(0, pos);
    			std::cout << token << std::endl;
    			line.erase(0, pos + delimiter.length());
			}
		}
	}

	std::cout<<line<<std::endl;
	// loop for login user
	bool invalid_login = true;
	while (invalid_login)
	{
		std::cout << "Please enter your username: ";
		std::cin >> username;
		std::cout << "Please enter your password: ";
		std::cin >> password;

		if (password == userRecord[username].getPass()){
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
