#pragma once
#include "User.h"
#include"Admin.h"
#include"BookMark.h"
#include <algorithm>
class RegisteredUser :public User
{
	struct CompareByRate 
	{
		bool operator()(News n1, News n2) const
		{
			return n1.GetAvg() > n2.GetAvg();
		}
	};
public:
	RegisteredUser();
	RegisteredUser(std::string name, std::string password);
	BookMark bookMark; //Roaa "REVIEWED"
	std::string getName();
	void search_by_keyword_of_title(unordered_map<int, News>map, std::string Uname); //Rokaya "REVIEWED"
	void DisplayCategorizedNews(string cate, unordered_map<std::string, set<News*>>& CaNe);//Rawan "REVIEWED"
	void RateNews(News& newsobject, float rating);//Mahmoud "REVIEWED"
	void DisplayTrendingNews(unordered_map<int, News> map);//Rawan "REVIEWED"
	void AddComment(string comment, News& news);//Roaa ""
	void spam(News& n);//Rawan
	RegisteredUser* Login(string name, string pass); //Eiad "REVIEWED"
	std::string getPass();
};