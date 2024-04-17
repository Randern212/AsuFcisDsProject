#pragma once
enum Month
{
	January, February, ....
};
class Date
{
	int day;
	Month month;
	year;
public:
	Date(int day, Month month, int year);
	bool isBefore();
};