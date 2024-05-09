#pragma once
#include<set>
#include<unordered_map>
#include "User.h"
#include"News.h"
#include"Date.h"
class Admin : public User
{
public:
	void Post();//Salsabil
	void Remove(vector <News> Newsvector); //Mahmoud
	void Update(News n);//Roaa
	void AddCategory();//Salsabil
};

