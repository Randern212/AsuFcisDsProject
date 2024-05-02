#include<iostream>
#include"News.h"
#include "User.h"
#include "Admin.h"
#include "RegisteredUser.h"
#include<set>
#include<unordered_map>
#include<assert.h>
#include<fstream>
int main()
{
	int input;
	User* currentUser;
	std::unordered_map<string, User> accounts; //the key is 
	std::cout << "To log-in press 1 to register press 2 \n";
	std::cin >> input;
	if (input == 1)
	{
		string name, password;
		std::cout << "username: \t";
		std::getline(std::cin,name);
		std::cout << "password: \t";
		std::getline(std::cin, password);
		currentUser = accounts[name].Login(name,password);
		if (currentUser != NULL)
		{

		}
	}
	else if(input==2)
	{
		string name, password;
		std::cout << "username: \t";
		std::getline(std::cin, name);
		std::cout << "password: \t";
		accounts.insert(std::make_pair(password, RegisteredUser(name, password)));
	}
}
