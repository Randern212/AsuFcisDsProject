#include<iostream>
#include"News.h"
#include "User.h"
#include "Admin.h"
#include "RegisteredUser.h"
#include<set>
#include<unordered_map>
using namespace std;

int main()
{
	set<News> allNews;
	unordered_map < string, set<News> > categories;
}