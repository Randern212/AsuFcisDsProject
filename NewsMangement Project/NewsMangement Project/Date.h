#pragma once
#include<string>
#include<iostream>
enum Month
{
	Jan, Feb, Mar, Apr, May, Jun, July, Jul, Aug, Sep, Oct, Nov, Dec
};
class Date //Sara
{
	int day;
	Month month;
	int year;
public:
	Date();
	Date(int day, Month month, int year);
	int GetDay();
	void SetDay(int d);
	bool LeapYear(int year);
	Month GetMonth();
	void SetMonth(int m);
	int GetYear();
	void SetYear(int y);
	bool IsBefore(Date& ODate);
};
