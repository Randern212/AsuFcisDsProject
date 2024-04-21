#pragma once
#include <iostream>
#include <vector>
#include <unordered_map>
#include "Date.h"
#include<stack>
class News //Eiad
{
	std::string title;
	std::string category;
	std::string description;
	std::vector<std::string> keyWords;
	std::unordered_map<std::string, float> ratings;

public:
	Date date;
	std::stack < std::pair<std::string , std::string >> Comment;//Roaa
	News(std::string directory);
	std::string GetTitle();
	void SetTitle(std::string s);
	std::string GetCategory();
	void SetCategory(std::string s);
	std::string GetDescription();
	void SetDescription(std::string s);
	void Rate(std::string userName, float rate);
	float SpecifiedRate(std::string userName);
	void DisplayNews();//Roaa
	void DisplayComment();//Roaa

};