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
	unordered_map < string, set<News> > categorized;
	unordered_map<string, unordered_map<string, RegisteredUser>> userList;
	User* currentUser;

}