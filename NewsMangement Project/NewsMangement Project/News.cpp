#include "News.h"


News::News(std::string directory)
{

}

void News::Rate(std::string userName, float rate)
{
	ratings[userName] = rate;
}

float News::specifiedRate(std::string userName)
{
	return ratings[userName];
}
