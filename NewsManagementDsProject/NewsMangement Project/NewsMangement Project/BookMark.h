#pragma once
#include"News.h"
#include<string>
#include<unordered_map>
class BookMark//Roaa
{
	std::unordered_map<int, News*> bookMarked;
public:
	void AddBookMark(int id, News& booked);
	void DisplayAllBookMarked();
	void RemoveBookMarked(int id);
	News* GetSpecificBookMarked(int id);
};
