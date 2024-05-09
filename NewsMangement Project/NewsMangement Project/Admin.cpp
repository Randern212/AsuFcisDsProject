#include "Admin.h"
void Admin::Post()
{

}
void Admin::Remove(vector<News> Newsvector)
{
}
void Admin::Remove(vector <News> Newsvector)
{
	int index;
	std::cout << "Enter the index of the news item you want to remove: ";
	std::cin >> index;

	if (index >= 0 && index > Newsvector.size()) {
		Newsvector.erase(Newsvector.begin() + index);
		std::cout << "News item remove successfully.";
	}
	else {
		std::cout << "Invalid index. ";
	}
}
void Admin::Update(News n)
{
	cout << "choose \'1\' if you want to add additional description \n choose \'2\' if you want to change the whole description";
	int num;
	cin >> num;
	string s;
	switch (num)
	{

	case 1:
		cout << "Enter the additional des";
		cin >> s;
		n.SetAdditonalDescription(s);
		break;
	case 2:
		cout << "Enter the new des";
		cin >> s;
		n.SetDescription(s);
		break;
	default:
		cout << "invalid number";
		break;
	}

}
void Admin::AddCategory()
{

}
