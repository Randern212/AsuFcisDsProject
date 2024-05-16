#include<iostream>
#include<fstream>
#include <sstream>
#include<string>
#include<algorithm>
#include"News.h"
#include "User.h"
#include "Admin.h"
#include "RegisteredUser.h"
#include<set>
#include<unordered_map>
#include<vector>

void Filoutput(const std::string& filename, unordered_map<int, News>& map);
set<News*> mapToSet(unordered_map<int, News>& m);
unordered_map<std::string, set<News*>> categLoad(unordered_map<int, News>& m);
int askForID();
unordered_map<int, News> FileToNewsDS(const std::string& filename);

int main() {
    std::unordered_map<int, News> AllNews = FileToNewsDS("DataSet_DS.txt"); // the key is the id
    std::set<News*> datedNews = mapToSet(AllNews); // the operator is the date
    std::unordered_map<std::string, std::set<News*>> categNews = categLoad(AllNews); // the 1st key is the category the 2nd is the ID
    std::unordered_map<std::string, RegisteredUser> accounts; // the key is the username since it is the unique part

    std::fstream fileAcc;
    fileAcc.open("AccountsData.txt", std::ios::in);
    if (fileAcc.is_open())
    {
        std::string line1, line2;
        while (fileAcc >> line1 >> line2)
        {
            accounts[line1] = RegisteredUser(line1, line2);
        }
        fileAcc.close();
    }

    int outerinput = 0;
    while (outerinput == 0)
    {
        std::cout << "To log-in press 1, to register press 2, to exit the application press any other key \n";
        std::cin >> outerinput;
        if (outerinput == 1)
        {
            RegisteredUser* currentUser;
            std::string name, password;
            std::cout << "username: \n";
            std::cin >> name;
            std::cout << "password: \n";
            std::cin >> password;

            if (name == "ADMIN" && password == "ADMIN")
            {
                Admin active = Admin();
                std::cout << "You are ADMIN \n";
                bool adminActive = true;
                while (adminActive)
                {
                    std::cout << "1-Post, 2-Remove, 3-Update, 4-Add a category, 5-Display the average rating, 6-Logout\n";
                    int input;
                    std::cin >> input;
                    News* tmpNews;
                    switch (input)
                    {
                    case 1:
                        active.Post(AllNews, categNews); // done
                        break;
                    case 2:
                        tmpNews = active.Remove(AllNews, askForID());
                        categNews = categLoad(AllNews);
                        datedNews = mapToSet(AllNews);
                        break;
                    case 3:
                        active.Update(AllNews.at(askForID())); // done
                        break;
                    case 4:
                        active.AddCategory(AllNews, categNews);
                        break;
                    case 5:
                        active.DisplayAvgRate(AllNews[askForID()]);
                        break;
                    case 6:
                        adminActive = false;
                        break;
                    default:
                        break;
                    }
                }
            }
            else
            {
                currentUser = accounts[name].Login(name, password);
                if (currentUser != NULL)
                {
                    std::cout << "You are logged in \n";
                    bool userActive = true;
                    while (userActive)
                    {
                        std::cout << "1-Search by ID, 2-Search by keywords, 3-Sort by date, 4-Choose category, 5-Rate News, 6-Bookmark tab, 7-Sort by rate, 8-Add comment, 9-Display comments for specific news, 10-Report news by their ID, 11-Logout\n";
                        int input;
                        std::cin >> input;
                        std::string inp;
                        int innerinp;
                        int commandi;
                        float rate;
                        News* specific;
                        switch (input)
                        {
                        case 1:
                            std::cout << "Enter ID:\n";
                            std::cin >> innerinp;
                            AllNews[innerinp].DisplayNews(currentUser->getName());
                            break;
                        case 2:
                            currentUser->search_by_keyword_of_title(AllNews, currentUser->getName());
                            break;
                        case 3:
                            for (auto& item : datedNews)
                            {
                                item->DisplayNews(currentUser->getName());
                            }
                            break;
                        case 4:
                            std::cout << "Enter category\n";
                            std::cin >> inp;
                            currentUser->DisplayCategorizedNews(inp, categNews);
                            break;
                        case 5:
                            std::cout << "Enter rating:\n";
                            std::cin >> rate;
                            currentUser->RateNews(AllNews[askForID()], rate);
                            break;
                        case 6:
                            std::cout << "Enter your command: 1-to display your bookmarked, 2-to Add news by their ID, 3-Remove news by their ID, 4-To get specific news by their ID\n";
                            std::cin >> commandi;
                            switch (commandi)
                            {
                            case 1:
                                currentUser->bookMark.DisplayAllBookMarked();
                                break;
                            case 2:
                                innerinp = askForID();
                                currentUser->bookMark.AddBookMark(innerinp, AllNews[innerinp]);
                                break;
                            case 3:
                                currentUser->bookMark.RemoveBookMarked(askForID());
                                break;
                            case 4:
                                specific = currentUser->bookMark.GetSpecificBookMarked(askForID());
                                specific->DisplayNews(currentUser->getName());
                                break;
                            default:
                                break;
                            }
                            break;
                        case 7:
                            currentUser->DisplayTrendingNews(AllNews);
                            break;
                        case 8:
                            std::cout << "Comment:\t";
                            std::cin >> inp;
                            AllNews[askForID()].addComment(currentUser->getName(), inp);
                            break;
                        case 9:
                            AllNews[askForID()].DisplayComment();
                            break;
                        case 10:
                            AllNews[askForID()].addReporter(currentUser->getName());
                            break;
                        case 11:
                            userActive = false;
                            break;
                        default:
                            break;
                        }
                    }
                }
            }
        }
        else if (outerinput == 2)
        {
            std::string name, password;
            std::cout << "username: \n";
            std::cin >> name;
            std::cout << "password: \n";
            std::cin >> password;
            accounts.insert(std::make_pair(name, RegisteredUser(name, password)));
        }
        else
            break;
        outerinput = 0;
    }

    Filoutput("DataSet_DS.txt", AllNews);
    fileAcc.open("AccountsData.txt", std::ios::out);
    if (fileAcc.is_open())
    {
        for (auto& item : accounts)
        {
            fileAcc << item.first << '\n';
            fileAcc << item.second.getPass() << '\n';
        }
        fileAcc.close();
    }
    return 0;
}

set<News*> mapToSet(unordered_map<int, News>& m)
{
    set<News*> tmp;
    for (auto& pair : m)
    {
        tmp.insert(&pair.second);
    }
    return tmp;
}

void Filoutput(const std::string& filename, unordered_map<int, News>& map)
{
    std::ofstream file(filename);
    if (!file.is_open()) {
        std::cerr << "Error opening file: " << filename << std::endl;
        return;
    }
    for (auto& pair : map)
    {
        file << pair.second.GetId() << '\t' << pair.second.GetTitle() << '\t' << pair.second.GetCategory() << '\t' << pair.second.GetDescription() << '\t' << pair.second.getDateAsString() << '\t' << pair.second.GetAvg() << '\n';
    }
    file.close();
    std::cout << "Done writing";
}

unordered_map<std::string, set<News*>> categLoad(unordered_map<int, News>& m)
{
    unordered_map<std::string, set<News*>> temp;
    for (auto& pair : m)
    {
        temp[pair.second.GetCategory()].insert(&pair.second);
    }
    return temp;
}

int askForID()
{
    int in;
    std::cout << "Enter the News' ID: ";
    std::cin >> in;
    return in;
}

unordered_map<int, News> FileToNewsDS(const std::string& filename)
{
    unordered_map<int, News> m;
    std::ifstream file(filename);
    std::string line;

    if (!file.is_open()) {
        std::cerr << "Error opening file: " << filename << std::endl;
        return m;
    }

    while (std::getline(file, line))
    {
        std::istringstream stst(line);
        std::vector<std::string> tokens;
        std::string token;
        while (std::getline(stst, token, '\t'))
            tokens.push_back(token);
        int id = std::stoi(tokens[0]);
        std::string title = tokens[1];
        std::string category = tokens[2];
        std::string description = tokens[3];
        std::string date = tokens[4];
        float avg = std::stof(tokens[5]);
        Date target = Date::strToDate(date);
        News tmp = News(id, title, category, description, target, avg);
        m.insert(std::make_pair(tmp.GetId(), tmp));
    }
    file.close();
    return m;
}