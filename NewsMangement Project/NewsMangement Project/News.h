#pragma once
#include <iostream>
#include <vector>
#include <unordered_map>
class News
{
	std::string Title;
	std::string Category;
	std::string Article;
	std::vector<std::string> keyWords;
	//date Date;
	std::unordered_map<std::string,float> ratings;
public:
	News(std::string directory);
	void Rate(std::string userName, float rate);
	float specifiedRate(std::string userName);

};