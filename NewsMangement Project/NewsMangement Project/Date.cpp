#include "Date.h"
Date::Date(int day, Month month, int year)
{
}
int Date::GetDay()
{
	return day;
}
void Date::SetDay(int d)
{
	day = d;
}
Month Date::GetMonth()
{
	return month;
}
void Date::SetMonth(int m)
{
	if (m == 1)
	{
		month = Jan;
	}
	//.......
	else if (m == 12)
	{
		month = Dec;
	}
	else
		std::cout << "invalid Month\n";
}
int Date::GetYear()
{
	return year;
}
int Date::SetYear(int y)
{
	year = y;
}
bool Date::IsBefore()
{
	return false;
}
