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
	void DisplayCategorizedNews();//Rawan
	void RateNews();//Mahmoud
	void DisplayTrendingNews();//Rawan
	void AddComment(string comment,News news);//Roaa
	void spam();//Rawan
};

