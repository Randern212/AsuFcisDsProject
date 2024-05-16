#pragma once
#include <iostream>
#include <vector>
#include <unordered_map>
#include "Date.h"
class News //Eiad
{
	int id;
	std::string title;
	std::string category;
	std::string description;
	float avgRate;
	std::vector<std::string> keyWords;
	//float sumofrates=0;
	std::unordered_map<std::string, float> ratings;
	std::vector<std::string>ReportingUsers;//Rawan 
	std::vector < std::pair<std::string, std::string >> Comment;//Roaa
	Date date;
public:
	News();
	News(int id, std::string title, std::string category, std::string description, Date date, float avgrate);
	std::string GetTitle();
	void SetTitle(std::string s);
	int GetId();
	void setID(int id);
	float GetAvg();
	std::string GetCategory();
	void SetCategory(std::string s);
	std::string GetDescription();
	void SetDescription(std::string s);
	void SetAdditonalDescription(std::string d);
	void Rate(std::string userName, float rate);
	float SpecifiedRate(std::string userName);
	void DisplayNews(std::string username);//Roaa & Rawan
	void DisplayComment();//Roaa
	float calculate_avgrate();//Rokaya
	int getRatingAmount();
	void setDate(int d,int m,int y);
	void addReporter(std::string uname); 
	void addComment(std::string uname,std::string com); 
	std::string getDateAsString();
	bool operator<(News ONews)const;
	bool operator>(News ONews)const;
	bool operator==(News ONews)const;
};
