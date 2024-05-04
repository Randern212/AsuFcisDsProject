#include "BookMark.h"
void BookMark::AddBookMark(int id, News booked)
{
	bookMarked[id] = booked;
	std::cout << "Added to bookmarks successfully ";

}
void BookMark::DisplayAllBookMarked()
{

	if (bookMarked.empty())
		std::cout << "Emptyyy !";
	else
	{
		for (auto& book : bookMarked)
		{
			std::cout << book.second.GetId() << "-" << book.second.GetTitle();

		}
	}
}
News BookMark::GetSpecificBookMarke(int id)
{
	return bookMarked[id];
}
void BookMark::RemoveBookMarke(int id)
{
	if (bookMarked.find(id) != bookMarked.end())
	{
		bookMarked.erase(id);
		std::cout << " Removed from BookMarks successfully";
	}
	else
		std::cout << " Not found";
}