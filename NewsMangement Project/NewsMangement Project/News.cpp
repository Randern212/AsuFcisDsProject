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
int News::GetId()
{
	return id;
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
}

float News::SpecifiedRate(std::string userName)
{
	return ratings[userName];
}
void  News::DisplayNews(std::string username)
{
	for (auto i : ReportingUsers) {
		if (i == username) {
			std::cout << "Hidden , This new has been reported";
		}
		else {
			std::cout << "Category: " << category << "\n";
			std::cout << "Title: " << title << "\n";
			std::cout << "Description: " << description << "\n";
			std::cout << "Date: " << date.GetDay() << "/ " << date.GetMonth() << "/ " << date.GetYear() << "\n";
			std::cout << "Number of spams on this new : " << ReportingUsers.size();
		}
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

