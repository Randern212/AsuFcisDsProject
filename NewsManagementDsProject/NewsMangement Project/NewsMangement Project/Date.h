#pragma once
#include<string>
//enum Month
//{
//	Jan, Feb, Mar, Apr, May, Jun, July, Jul, Aug, Sep, Oct, Nov, Dec
//};
class Date //Sara
{
	int day;
	//Month month;
	int month;
	int year;
public:
	Date();
	Date(int day, int month, int year);
	static Date strToDate(std::string);
	int GetDay();
	void SetDay(int d);
	//bool LeapYear(int year);
	int GetMonth();
	void SetMonth(int m);
	int GetYear();
	void SetYear(int y);
	bool operator<(Date ODate) const;
	bool operator>(Date ODate) const;
	bool operator==(Date ODate) const;
};
