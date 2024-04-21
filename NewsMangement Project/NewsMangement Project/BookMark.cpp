#include "BookMark.h"
void BookMark::AddBookMark
(std::string title, News booked)
{
	bookMarked[title] = booked;
	std::cout << title << "Added to bookmarks ";

}
void BookMark::DisplayAllBookMarked()
{

	if (bookMarked.empty())
		std::cout << "Emptyyy !";
	else
	{
		for (auto& book : bookMarked)
		{
			std::cout << book.first;

		}
	}
}
News BookMark::GetSpecificBookMarke(std::string title)
{
	return bookMarked[title];
}
void BookMark::RemoveBookMarke(std::string title)
{
	if (bookMarked.find(title) != bookMarked.end())
	{
		bookMarked.erase(title);
		std::cout << title << " Removed from BookMarks successfully";
	}
	else
		std::cout << title <<" Not found";
}