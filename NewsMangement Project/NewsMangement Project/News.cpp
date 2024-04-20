#include "News.h"
News::News(std::string directory)
{

}

std::string News::GetTitle()
{
	return title;
}
void News::SetTitle(std::string t)
{
	title = t;
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

void News::Rate(std::string userName, float rate)
{
	ratings[userName] = rate;
}

float News::SpecifiedRate(std::string userName)
{
	return ratings[userName];
}
void  News::Display()
{
	std::cout << "Category: " << category << "\n";
	std::cout << "Title: " << title << "\n";
	std::cout << "Description: " << description << "\n";
	std::cout << "Date: " << date.GetDay() << "/ " << date.GetMonth() << "/ " << date.GetYear() << "\n";
}
