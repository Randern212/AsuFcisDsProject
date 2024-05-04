#pragma once
#include<set>
#include<unordered_map>
#include "User.h"
#include"News.h"
#include"Date.h"
class Admin : public User
{
public:
	static set<News> allNews;
	static unordered_map < string, set<News> > categorized;
	void Post();//Salsabil
	void Remove();//Mahmoud
	void Update(News n);//Roaa
	void AddCategory();//Salsabil
	float DisplayAverageRate();//Rokaya
};

