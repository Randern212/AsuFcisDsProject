#include "RegisteredUser.h"
void RegisteredUser::Register()
{

}
void  RegisteredUser::Search()
{

}
void  RegisteredUser::DisplayLatestNews()
{

}
void  RegisteredUser::DisplayCategorizedNews(string cate, News n)
{

	auto it = Admin::categorized.find(cate);
	if (it != Admin::categorized.end()) {

		for (auto article : it->second) {
			n.DisplayNews(name);
		}
	}
	else
	{
		cout << "Sorry , the category you have entered is not found";
	}
}
void  RegisteredUser::RateNews(News newsobject, float rating)
{

	std::cout << "News rated with rating " << rating << endl;
	newsobject.Rate(name, rating);

}
void  RegisteredUser::DisplayTrendingNews()
{

}
void  RegisteredUser::AddComment(string comment,News news)
{

	news.Comment.push_back({ name, comment });


}
void  RegisteredUser::spam()
{

}


