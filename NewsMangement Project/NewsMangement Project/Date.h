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
	Date(int day, Month month, int year);
	int GetDay();
	void SetDay(int d);
	Month GetMonth();
	void SetMonth(int m);
	int GetYear();
	int SetYear(int s);
	void Rate(std::string userName, float rate);
	bool IsBefore();
};