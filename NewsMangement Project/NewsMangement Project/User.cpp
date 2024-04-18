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
bool User::Login(string name, string pass)
{

}