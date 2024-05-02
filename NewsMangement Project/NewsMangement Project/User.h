#pragma once
#include<string>
#include "News.h"
using namespace std;
class User
{
protected:
	string name;
	string password;

public:
	User();
	User(string na, string pass);
	User* Login(string name, string pass);
};
