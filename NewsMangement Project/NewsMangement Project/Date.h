#pragma once
enum Month
{
	//January, February, ...
};
class Date //Sara
{
	int day;
	Month month;
	int year;
public:
	Date(int day, Month month, int year);
	bool isBefore();
};