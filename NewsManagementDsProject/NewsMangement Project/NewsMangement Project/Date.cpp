#include "Date.h"
#include<sstream>
Date::Date()
{
}
Date::Date(int d, int m, int y)
{
	day = d;
	year = y;
	month=m;
}
Date Date::strToDate(std::string dateStr)
{
	int day, year;
	int month;
	char slash;

	std::istringstream iss(dateStr);
	iss >> month >> slash >> day >> slash >> year;
	Date target = Date(day, month, year);
	return target;
}
int Date::GetDay()
{
	return day;
}
//bool Date::LeapYear(int year) {
//	if ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0)) {
//		return true;
//	}
//	else {
//		return false;
//	}
//}
void Date::SetDay(int d)
{
	day = d;
	/*if (d >= 1 && d <= 31) {
		switch (month) {
		case Jan:
		case Mar:
		case May:
		case Jul:
		case Aug:
		case Oct:
		case Dec:
			day = d;
			break;
		case Apr:
		case Jun:
		case Sep:
		case Nov:
			if (d <= 30) {
				day = d;
			}
			else {
				std::cout << "Invalid day for this month\n";
			}
			break;
		case Feb:
			if (LeapYear(year)) {
				if (d <= 29) {
					day = d;
				}
				else {
					std::cout << "Invalid day for February\n";
				}
			}
			else {
				if (d <= 28) {
					day = d;
				}
				else {
					std::cout << "Invalid day for February\n";
				}
			}
			break;
		default:
			std::cout << "Invalid month\n";
		}
	}
	else {
		std::cout << "Invalid day\n";
	}*/
}
int Date::GetMonth()
{
	return month;
}
void Date::SetMonth(int m)
{
	month = m;
	/*switch (m) {
	case 1:  month = Jan; break;
	case 2:  month = Feb; break;
	case 3:  month = Mar; break;
	case 4:  month = Apr; break;
	case 5:  month = May; break;
	case 6:  month = Jun; break;
	case 7:  month = Jul; break;
	case 8:  month = Aug; break;
	case 9:  month = Sep; break;
	case 10: month = Oct; break;
	case 11: month = Nov; break;
	case 12: month = Dec; break;
	default: std::cout << "Invalid month\n"; break;
	}*/
}
int Date::GetYear()
{
	return year;
}
void Date::SetYear(int y)
{
	year = y;
}

bool Date::operator<( Date ODate) const
{
		if (year != ODate.year)
			return year < ODate.year;
		if (month != ODate.month)
			return month < ODate.month;
		return day < ODate.day;
}

bool Date::operator>(Date ODate) const
{
	if (year != ODate.year)
		return year > ODate.year;
	if (month != ODate.month)
		return month > ODate.month;
	return day > ODate.day;
}

bool Date::operator==(Date ODate) const
{
	return(year == ODate.year && month == ODate.month && day == ODate.day);
}
