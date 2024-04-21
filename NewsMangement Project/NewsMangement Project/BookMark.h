#pragma once
#include"News.h"
#include<string>
#include<unordered_map>
class BookMark//Roaa
{
	std::unordered_map<std::string, News> bookMarked;
public:
	void AddBookMark(std::string title, News booked);
	void DisplayAllBookMarked();
	void RemoveBookMarke(std::string title);
	News GetSpecificBookMarke(std::string title);
};

