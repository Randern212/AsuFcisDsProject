#include<iostream>
#include"News.h"
#include "User.h"
#include "Admin.h"
#include "RegisteredUser.h"
#include<set>
#include<unordered_map>
#include<assert.h>
#include<fstream>
set<News> vecToSet(vector<News> v);
unordered_map<std::string, News> vecToMap(vector<News> v);
unordered_map<std::string, set<News>> categLoad(vector<News> v);
int main()
{
	vector<News> AllNews;
	set<News> datedNews = vecToSet(AllNews);
	unordered_map<std::string, set<News>> categNews = categLoad(AllNews);
	unordered_map<std::string, News> AllNewsMap =vecToMap(AllNews);
	std::unordered_map<string, RegisteredUser> accounts; //the key is the username since it is the unique part
	
	
	std::fstream fileAcc;
	fileAcc.open("AccountsData.txt", std::ios::in);
	if (fileAcc.is_open())
	{
		std::string line1, line2;
		while (fileAcc >> line1 >> line2)
		{
			accounts[line1] = RegisteredUser(line1, line2);
		}
		fileAcc.close();
	}
	while (true)
	{
		int input;
		std::cout << "To log-in press 1 to register press 2 \n";
		std::cin >> input;
		if (input == 1)
		{
			RegisteredUser* currentUser;
			string name, password;
			std::cout << "username: \t";
			std::getline(std::cin, name);
			std::cout << "password: \t";
			std::getline(std::cin, password);
			currentUser = accounts[name].Login(name, password);
			if (name == "ADMIN" && password == "ADMIN")
			{
				Admin active = Admin();
				std::cout << "You are ADMIN \n";
				std::cout << "1-Post, 2-Remove, 3-update, 4-Add a category,5-Display the average rating, Anything else,Logut\n";
				std::cin >> input;
				switch (input)
				{
				case 1:
					active.Post();
					break;
				case 2:
					active.Remove();
					break;
				case 3:
					//active.Update();
					break;
				case 4:
					active.AddCategory();
					break;
				case 5:
					active.DisplayAverageRate();
					break;
				default:
					break;
				}
			}
			if (currentUser != NULL && currentUser->getName() != "ADMIN")
			{
				std::cout << "You are logged in \n";
				std::cout << "1-Search, 2-Sort by rate, 3-sort by date, 4-Choose category, 5-Bookmark Title, Anything else-Logout\n";
				std::cin >> input;
				std::string inp;
				switch (input)
				{
				case 1:
					std::cout << "Enter title\n";
					std::cin >> inp;
					AllNewsMap[inp].DisplayNews(currentUser->getName());
					break;
				case 2:
					break;
				case 3:
					for (auto item: datedNews)
					{
						item.DisplayNews(currentUser->getName());
					}
					break;
				case 4:
					std::cout << "Enter category\n";
					std::cin >> inp;
					for (auto item : categNews[inp])
					{
						item.DisplayNews(currentUser->getName());
					}
					break;
				case 5:
					break;
				default:
					break;
				}
			}
		}
		else if (input == 2)
		{
			string name, password;
			std::cout << "username: \t";
			std::getline(std::cin, name);
			std::cout << "password: \t";
			std::getline(std::cin, password);
			accounts.insert(std::make_pair(password, RegisteredUser(name, password)));
		}
	}
}

set<News> vecToSet(vector<News> v)
{
	set<News> tmp(v.begin(), v.end());
	return tmp;
}

unordered_map<std::string, News> vecToMap(vector<News> v)
{
	unordered_map<std::string, News> temp;
	for (News item : v)
	{
		temp.insert(std::make_pair(item.GetTitle(),item));
	}
	return temp;
}

unordered_map<std::string, set<News>> categLoad(vector<News> v)
{
	unordered_map<std::string, set<News>> temp;
	for (News item : v)
	{
		temp[item.GetCategory()].insert(item);
	}
	return temp;
}
