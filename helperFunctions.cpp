#include "helperFunctions.h"

using namespace std;
HANDLE console = GetStdHandle(STD_OUTPUT_HANDLE);
COORD cursorPosition;

void gotoXY(int x, int y)
{
    cursorPosition.X = x;
    cursorPosition.Y = y;
    SetConsoleCursorPosition(console, cursorPosition);
}
//display header of main menu
void menuHeader(string title)
{
    gotoXY(20, 0);
    cout << "#################################################";
    gotoXY(20, 1);
    cout << "##                " << title << "               ##";
    gotoXY(20, 2);
    cout << "#################################################";
}
//display header of main menu
//display menu items
void showMenuItems(vector<string> items)
{
    gotoXY(20, 4);
    cout << "+-----------------------------------------------+";
    gotoXY(20, 5);
    cout << "|                                               |";
    gotoXY(20, 6);
    cout << "|                   Main menu                   |";
    gotoXY(20, 7);
    cout << "|                                               |";

    for (int i = 0; i < items.size(); i++)
    {

        gotoXY(20, i + 8);
        cout << "|                                               |";
        gotoXY(25, i + 8);
        cout << items[i];
    }
    gotoXY(20, (8 + items.size()));
    cout << "|                                               |";
    gotoXY(20, (8 + items.size() + 1));
    cout << "+-----------------------------------------------+ \n \n";
}
//display menu items

void printRestaurant(string name, string adrress, string telNumb)
{
    gotoXY(20, 5);
    cout << "Your current information";
    gotoXY(20, 7);
    cout << "Restaurant name : " << name;
    gotoXY(20, 9);
    cout << "Restaurant adrress : " << adrress;
    gotoXY(20, 11);
    cout << "Restaurant telephone number : " << telNumb;
    gotoXY(20, 12);
    cout << "------------------------------------------------";
}
void printRestaurants(restaurantList *list)
{
    int i = 0;
    for (restaurant r : list->getRestaurants())
    {
        gotoXY(5, i);
        cout << r.getRestaurantName();
        gotoXY(45, i);
        cout << r.getRestaurantAdrress();
        gotoXY(45, i + 1);
        cout << r.getRestaurantTelNumb();
        i += 3;
    }
}
void printReviews(reviewList *revs)
{
    int y = 0;
    for (review rev : revs->getReviews())
    {
        gotoXY(5, y);
        cout << "Author : " << rev.getAuthor() << endl;
        gotoXY(5, y + 2);
        cout << "Restaurant Name : ";

        cout << rev.getRestaurantName() << endl;

        gotoXY(5, y + 4);
        cout << "Review";
        gotoXY(42, y + 4);
        cout << "Points : " << rev.getPoints() << "/10";
        gotoXY(5, y + 5);
        cout << rev.getReviewText();
        gotoXY(5, y + 6);
        cout << "--------------------------------------------------" << endl;
        y += 7;
    }
}

vector<string> getSearchedData(string fileName, string searchTerm)
{
    vector<string> record;
    fstream file;
    bool foundRecord = false;
    string str, fieldOne, fieldTwo, fieldThree;

    file.open(fileName);

    while (getline(file, fieldOne, ',') && !foundRecord)
    {
        getline(file, fieldTwo, ',');
        getline(file, fieldThree, '\n');
        if (fieldOne == searchTerm)
        {
            foundRecord = true;
            record.push_back(fieldOne);
            record.push_back(fieldTwo);
            record.push_back(fieldThree);
        }
    }

    file.close();
    return record;
}

string encryptDecrypt(string toEncrypt)
{
    string key = "jAn";
    string output = toEncrypt;

    for (int i = 0; i < toEncrypt.size(); i++)
        output[i] = toEncrypt[i] ^ key[i % key.size()];

    return output;
}
void noRestaurantMsg()
{
    gotoXY(20, 5);
    cout << "You don't have restaurant :( ...";
    gotoXY(20, 7);
    cout << "Press enter to back to main menu";
    cin.get();
}
string getNewRestaurantInfo(string username)
{
    string restaurantName, restaurantAdrress, restaurantNumb, info;
    gotoXY(20, 14);
    cout << "Your new information";
    while (restaurantName.empty())
    {
        gotoXY(20, 16);
        cout << "Restaurant name : ";
        getline(cin, restaurantName);
    }
    while (restaurantAdrress.empty())
    {
        gotoXY(20, 18);
        cout << "Restaurant adrress : ";
        getline(cin, restaurantAdrress);
    }
    while (restaurantNumb.empty())
    {
        gotoXY(20, 20);
        cout << "Restaurant telephone number : ";
        getline(cin, restaurantNumb);
    }
    info = restaurantName + "," + restaurantAdrress + "," + restaurantNumb + "," + username;
    return info;
}
string getAnswer()
{
    string choice;

    cout << "Are you sure ? y/n : ";
    cin >> choice;

    return choice;
}
string getReviewInfo(string username)
{

    string restaurantName, reviewText;
    int points = 0;
    gotoXY(20, 5);
    cout << "Restaurant name : ";
    getline(cin, restaurantName);
    gotoXY(20, 7);
    cout << "Your review : ";
    getline(cin, reviewText);
    while (!isdigit(points))
    {
        if (points >= 0 && points <= 10)
        {
            gotoXY(20, 9);
            cout << "Points (0-10) : ";
            cin >> points;
            break;
        }
    }

    return username + "," + restaurantName + "," + reviewText + "," + to_string(points);
}

string getRestaurantInfo(string username)
{
    string restaurantName, restaurantAddress, telNumber;

    gotoXY(20, 2);
    cout << "Enter restaurant name : ";
    getline(cin, restaurantName);
    gotoXY(20, 4);
    cout << "Enter adrress of your restaurant : ";
    getline(cin, restaurantAddress);
    gotoXY(20, 6);
    cout << "Entery your telephone number : ";
    getline(cin, telNumber);

    return restaurantName + "," + restaurantAddress + "," + telNumber + "," + username;
}
string getRestaurantName()
{
    string resName;
    gotoXY(20, 5);
    cout << "Restaurant name : ";
    getline(cin, resName);
    system("cls");
    return resName;
}