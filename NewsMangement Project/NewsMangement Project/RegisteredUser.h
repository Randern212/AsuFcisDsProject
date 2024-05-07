#pragma once
#include "User.h"
#include"Admin.h"
#include"BookMark.h"
class RegisteredUser :public User
{
public:
	RegisteredUser(std::string name, std::string password);
	BookMark bookMark; //Roaa 
	void Search();
	void DisplayLatestNews();
	void DisplayCategorizedNews(string cate, News n);//Rawan
	void RateNews(News newsobject, float rating);//Mahmoud
	void DisplayTrendingNews();//Rawan
	void AddComment(string comment,News news);//Roaa
	void spam();//Rawan
	RegisteredUser* Login(string name, string pass);
};

