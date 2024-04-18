#pragma once
#include <iostream>
#include <vector>
#include <unordered_map>
#include "Date.h"
class News //Eiad
{
	std::string Title;
	std::string Category;
	std::string Article;
	std::vector<std::string> keyWords;
	Date date;
	std::unordered_map<std::string,float> ratings;
public:
	News(std::string directory);
	void Rate(std::string userName, float rate);
	float specifiedRate(std::string userName);

};