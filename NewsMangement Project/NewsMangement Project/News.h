#pragma once
#include <iostream>
#include <vector>
#include <unordered_map>
#include "Date.h"
#include<stack>
class News //Eiad
{
	int id;
	std::string title;
	std::string category;
	std::string description;
	std::vector<std::string> keyWords;
	std::unordered_map<std::string, float> ratings;

public:
	News();
	std::vector<std::string>ReportingUsers;//Rawan 
	Date date;
	std::vector < std::pair<std::string , std::string >> Comment;//Roaa
	std::string GetTitle();
	void SetTitle(std::string s);
	int GetId();
	std::string GetCategory();
	void SetCategory(std::string s);
	std::string GetDescription();
	void SetDescription(std::string s);
	void SetAdditonalDescription(std::string d);
	void Rate(std::string userName, float rate);
	float SpecifiedRate(std::string userName);
	void DisplayNews(std::string username);//Roaa & Rawan
	void DisplayComment();//Roaa
	float calculate_avgrate();
};
