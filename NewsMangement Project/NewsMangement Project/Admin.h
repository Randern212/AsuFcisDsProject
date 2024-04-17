#pragma once
#include "User.h"
class Admin : public User
{
	void Post();
	void Remove();
	void Update();
	void AddCategory();
	float DisplayAverageRate();
};

