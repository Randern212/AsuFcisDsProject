#include "Admin.h"
void Admin::Post()
{

}
void Admin::Remove()
{

}
void Admin::Update()
{
	int i = 1;
	int num1, num2;
	bool wrongInput = 1;
	cout << "Please Choose News by it's Num. to Update \n";
	for (auto& it : news)
	{
		cout << i << "- ";
		it.DisplayNews();
		cout << "\n";
		i++;
	}
	cin >> num1;
	cout << " Which You to Update:\n 1- Title 2- Description 3-Date 4-Category ? \n";
	cin >> num2;
	string neew;
	while (wrongInput)
	{
		switch (num2)
		{
		case 1:
			cout << "Enter New Title\n";
			cin >> neew;
			news[num1 - 1].SetTitle(neew);
			wrongInput = 0;
			break;
		case 2:
			cout << "Enter New  Description\n";
			cin >> neew;
			news[num1 - 1].SetDescription(neew);
			wrongInput = 0;
			break;
		case 3:
			int da;
			int mo;
			int ye;
			cout << "Please Enter New Date\n";
			cout << "Please Enter the Day\n";
			cin >> da;
			news[num1 - 1].date.SetDay(da);
			cout << "Please Enter the Month\n";
			cin >> mo;
			news[num1 - 1].date.SetMonth(mo);
			cout << "Please Enter the Year\n";
			cin >> ye;
			news[num1 - 1].date.SetYear(ye);
			wrongInput = 0;
			break;
		case 4:
			cout << "Enter New  Category \n";
			cin >> neew;
			news[num1 - 1].SetCategory(neew);
			wrongInput = 0;
			break;

		default:
			cout << "You Have Entered Wrong number , please choose num from 1:4 \n";
			cin >> num2;
			wrongInput = 1;
			break;
		}

	}

}
void Admin::AddCategory()
{

}
float Admin::DisplayAverageRate()
{

}

