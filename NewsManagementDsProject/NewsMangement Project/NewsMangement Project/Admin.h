#pragma once
#include<set>
#include<unordered_map>
#include "User.h"
#include"News.h"
#include"Date.h"
class Admin : public User
{
public:
	void Post(unordered_map<int, News>& map, unordered_map<std::string, set<News*>>& cn);//Salsabil "REVIEWED"
	News* Remove(unordered_map<int, News>& map, int i); //Mahmoud "REVIEWED"
	void Update(News& n);//Roaa "REVIEWED"
	void AddCategory(unordered_map<int, News>& map, unordered_map<std::string, set<News*>>& cn);//Salsabil "REVIEWED"
	void DisplayAvgRate(News& n); //Rokaya "REVIEWED"
};

