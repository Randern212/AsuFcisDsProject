#include "Admin.h"
void Admin::Post()
{

}
void Admin::Remove()
{

}
void Admin::Update(News n)
{
	cout << "choose \'1\' if you want to add additional discription \n choose \'2\' if you want to change the whole discription";
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
float Admin::DisplayAverageRate()
{

}

