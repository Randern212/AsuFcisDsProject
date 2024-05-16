#include "Admin.h"
#include<unordered_map>

void Admin::Post(unordered_map<int,News>& map, unordered_map<std::string, set<News*>>& cn)
{
	News newNews= News();
	string t;
	int d,m,y;
	cout << "Enter ID\n";
	cin >> d;
	newNews.setID(d);
	cout << "Enter the title\n";
	cin >> t;
	newNews.SetTitle(t);
	cout << "Enter the category\n";
	cin >> t;
	newNews.SetCategory(t);
	cout << "Enter the Date \n Enter the day then month then year\n";
	cin >> d>>m>>y;
	newNews.setDate(d, m, y);
	cout << "Enter the description\n";
	cin >> t;
	newNews.SetDescription(t);
	map.insert(std::make_pair(newNews.GetId(), newNews));
	//dn.insert(&newNews);
	cn[newNews.GetCategory()].insert( &newNews);
}
News* Admin::Remove(unordered_map<int, News>& map,int i)
{
	News* tmp = &map[i];
	map.erase(i);
	return tmp;
}
void Admin::Update(News& n)
{
	cout << "choose \'1\' if you want to add additional description \n choose \'2\' if you want to change the whole description";
	int num;
	cin >> num;
	string s;
	switch (num)
	{

	case 1:
		cout << "Enter the additional description";
		cin >> s;
		n.SetAdditonalDescription(s);
		break;
	case 2:
		cout << "Enter the new description";
		cin >> s;
		n.SetDescription(s);
		break;
	default:
		cout << "invalid number";
		break;
	}

}
void Admin::AddCategory(unordered_map<int, News>& map, unordered_map<std::string, set<News*>>& cn)
{
	std::string newCategory;
	std::cout << "Enter the new category's name\n";
	std::cin >> newCategory;
	int in;
	std::cout << "Enter the News' ID that you want to transfer to the new category \n";
	std::cin >> in;
	//dn.erase(&map[in]);
	map[in].SetCategory(newCategory);
	//dn.insert(&map[in]);
	cn[newCategory].insert( &map[in]);
	/*
	std::string decision;
	std::cout << "Do you want to add news to an existing category? (yes/no): ";
	std::cin >> decision;
	std::string category, title, description;
	std::cout << "Enter the category name: ";
	std::cin >> category;
	std::cout << "Enter the news title: ";
	std::cin >> title;
	std::cout << "Enter the news description: ";
	std::cin >> description;
	News newsObj =  News();
	newsObj.SetTitle(title);
	newsObj.SetCategory(category);
	newsObj.SetDescription(description);
	if (decision == "yes")
	{
		if (categories.find(category) != categories.end())
		{
			categories[category].insert(newsObj);
		}
		else
		{
			std::cout << "Category does not exist.\n";
		}
	}
	else
	{
		categories[category].insert(newsObj);
	}*/
}
void Admin::DisplayAvgRate(News& n)
{
	if(n.getRatingAmount()==0)
		std::cout << "this id of news has no average rate" << std::endl;
	else
	{
			std::cout << "average rate of this id: " << n.GetId() << " is: " << n.GetAvg() << '\n';
	}
	/*int id;
	std::cout << " enter id of news you want to display avgrate" << ::endl;
	bool f = false;
	std::cin >> id;
	for (auto it : map)
	{
		if (id == it.GetId()) 
		{
			if (it.second.getRatingAmount() == 0)
			{
				f = true;
				std::cout << "this id of news has no average rate" << std::endl;
				break;
			}
			else 
			{
				float x = it.calculate_avgrate();
				std::cout << "average rate of this id:" << id << "is:" << x << std::endl;
				f = true;
				break;
			}
		}
		else
			f = false;
	}
	if (f == false)
		std::cout << "this id isn't found" << std::endl;*/
}
