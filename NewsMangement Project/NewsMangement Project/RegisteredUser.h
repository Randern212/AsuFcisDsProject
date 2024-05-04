#pragma once
#include "User.h"
#include"Admin.h"
#include"BookMark.h"
class RegisteredUser :public User
{
public:
	BookMark bookMark; //Roaa 
	void Register();
	void Search();
	void DisplayLatestNews();
	void DisplayCategorizedNews(string cate, News n);//Rawan
	void RateNews(News newsobject, float rating);//Mahmoud
	void DisplayTrendingNews();//Rawan
	void AddComment(string comment,News news);//Roaa
	void spam();//Rawan
};

