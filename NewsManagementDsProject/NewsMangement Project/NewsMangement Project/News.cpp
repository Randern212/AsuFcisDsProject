#include "News.h"
News::News() 
{
}
News::News(int id,std::string title,std::string category,std::string description,Date date,float avgrate) 
{	
	this->id = id;
	this->avgRate = avgrate;
	this->category = category;
	this->date = date;
	this->description = description;
	this->title = title;
}

std::string News::GetTitle()
{
	return title;
}
void News::SetTitle(std::string t)
{
	title = t;
}
int News::GetId()
{
	return id;
}
float News::GetAvg() {
	return avgRate;
}
void News::setID(int i)
{
	id = i;
}
std::string News::GetCategory()
{
	return category;
}
void News::SetCategory(std::string c)
{
	category = c;
}
std::string News::GetDescription()
{
	return description;
}
void News::SetDescription(std::string d)
{
	description = d;
}
void News::SetAdditonalDescription(std::string d)
{
	description = description + " " + d;
}

void News::Rate(std::string userName, float rate)
{
	ratings[userName] = rate;
	avgRate = calculate_avgrate();
}

float News::SpecifiedRate(std::string userName)
{
	return ratings[userName];
}
void News::DisplayNews(std::string username)
{
	if (avgRate < 2.0) {
		std::cout << " Hidden ";
	}
	else 
	{
		for (auto i : ReportingUsers)
		{
			if (i == username)
			{
				std::cout << "Hidden , This news have been reported";
				return;
			}
		}
		std::cout << "****************************************\n";
		std::cout << "ID: " << id << "\n";
		std::cout << "Title: " << title << "\n";
		std::cout << "Date: " << date.GetDay() << "/ " << date.GetMonth() << "/ " << date.GetYear() << "\n";
		std::cout << "Category: " << category << "\n";
		std::cout << "Description: " << description << "\n";
		std::cout << "Number of spams on this new : " << ReportingUsers.size()<<'\n';
		std::cout << "****************************************\n";
	}
}
void  News::DisplayComment()
{
	if (Comment.empty())
		std::cout << "there is no comments for this news ";
	else
	{
		for (auto& com : Comment)
		{
			std::cout << "[" << com.first << "] " << com.second << "\n";
		}

	}

}
float News::calculate_avgrate()
{
	float sumofrates = 0;
	for (auto pair:ratings)
	{
		sumofrates += pair.second;
	}
	float tmp = sumofrates / ratings.size();
	return tmp;
		//if (ratings.size() == 1) {
		//	sumofrates = ratings.begin()->second;
		//}
		//else {
		//	sumofrates += (ratings.end())->second;
		//}
		//float avgrate = sumofrates / ratings.size();
		//return avgrate;

	/*
	float sum_of_rates;
	auto pnt = ratings.end()--;
	if (ratings.size() == 1)
	{
		sum_of_rates = 0;
		sum_of_rates += pnt->second;
	}
	else
	{
		sum_of_rates += pnt->second;
	}

	float avgrate = sum_of_rates / ratings.size();

	return avgrate;*/
}

void News::setDate(int d, int m, int y)
{
	this->date = Date(d,m,y);
}

int News::getRatingAmount()
{
	return this->ratings.size();
}

bool News::operator<(News ONews) const
{
	return (date<ONews.date);
}

std::string News::getDateAsString()
{
	std::string dateString = "" + date.GetMonth() + '/' + date.GetDay() + '/' + date.GetYear();
	return dateString;
}

bool News::operator>(News ONews) const
{
	return (date > ONews.date);
}

bool News::operator==(News ONews) const
{
	return (date == ONews.date);
}

void News::addComment(std::string uname,std::string com )
{
	Comment.push_back(std::make_pair(uname, com));
}

void News::addReporter(std::string uname)
{
	ReportingUsers.push_back(uname);
}

