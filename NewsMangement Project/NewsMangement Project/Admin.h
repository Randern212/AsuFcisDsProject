#pragma once
#include<set>
#include<unordered_map>
#include "User.h"
#include"News.h"
#include"Date.h"
class Admin : public User
{
	set<News> allNews;
	vector<News> news;
	unordered_map < string, set<News> > categorized;
	void Post();//Salsabil
	void Remove();//Mahmoud
	void Update();//Roaa
	void AddCategory();//Salsabil
	float DisplayAverageRate();//Rokaya
};

