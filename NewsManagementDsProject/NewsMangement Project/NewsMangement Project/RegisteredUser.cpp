#include "RegisteredUser.h"
RegisteredUser::RegisteredUser()
{
}
RegisteredUser::RegisteredUser(std::string name, std::string password)
{
	this->name = name;
	this->password = password;
}

std::string RegisteredUser::getName()
{
	return this->name;
}

void RegisteredUser::search_by_keyword_of_title(unordered_map<int, News> map, std::string Uname)
{
	bool f = false;
	std::string keyword_of_title;
	std::cout << "enter keyword_of_title of news \n";
	std::cin >> keyword_of_title;
	for (auto it : map)
	{
		string s = it.second.GetTitle();
		if (s.find(keyword_of_title))
		{
			it.second.DisplayNews(Uname);
			f = true;
		}
	}
	if (!f)
		std::cout << " there isn't any title contains this keyword \n";
}

void  RegisteredUser::DisplayCategorizedNews(string cate, unordered_map<std::string, set<News*>>& CaNe)
{
	/*for (auto& item : CaNe[cate])
	{
		item.second->DisplayNews(name);
	}*/
	auto it = CaNe.find(cate);
	if (it != CaNe.end()) 
	{
		for (auto article : it->second) 
		{
			article->DisplayNews(name);
		}
	}
	else
	{
		cout << "Sorry , the category you have entered is not found";
	}
}
void  RegisteredUser::RateNews(News& newsobject, float rating)
{
	newsobject.Rate(name, rating);
	std::cout << "News rated with rating " << rating << '\n';
}

//bool RegisteredUser::CompareByRate(News n1, News n2)
//{
//	return (n1.GetAvg() > n2.GetAvg());
//}
void  RegisteredUser::DisplayTrendingNews(unordered_map<int,News> map)
{
	vector<News> tmpV;
	for (auto& item : map)
	{
		tmpV.push_back(item.second);
	}

	std::sort(tmpV.begin(), tmpV.end(), CompareByRate());

	for (auto& i : tmpV) 
	{
		i.DisplayNews(name);
	}
}
void  RegisteredUser::AddComment(string comment, News& news)
{
	news.addComment( name, comment );
}
void  RegisteredUser::spam(News& n)
{
	n.addReporter(name);
}

RegisteredUser* RegisteredUser::Login(string name, string pass)
{
	if (this->name == name && pass == password)
	{
		return this;
	}
	else
		return NULL;
}

std::string RegisteredUser::getPass()
{
	return password;
}
