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
	static bool  Login(string name, string pass);
};

