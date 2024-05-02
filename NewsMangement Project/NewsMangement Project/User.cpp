#include "User.h"
User::User()
{
	name = password = "";
}
User::User(string na, string pass)
{
	name = na;
	password = pass;
}
User* User::Login(string na, string pass)
{
	if (na == name && pass == password)
	{
		return this;
	}
	else
		return NULL;
}
