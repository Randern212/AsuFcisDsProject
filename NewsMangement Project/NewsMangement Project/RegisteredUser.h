#pragma once
#include "User.h"
class RegisteredUser :public User
{
	vector<News> Bookmarked;
public:
	void Register();
	void Search();
	void DisplayLatestNews();
	void DisplayCategorizedNews();//Rawan
	void RateNews();//Mahmoud
	void DisplayTrendingNews();//Rawan
	void Comment();//Roaa
	void spam();//Rawan
	void BookMark(string Title, unordered_map<string, News> DataHolder);//Roaa
};

