//#include "restaurantClasses.h"
#include "helperFunctions.h"

using namespace std;
//####################################################
restaurant::restaurant(string restaurantInfo)
{
    stringstream restaurantStream(restaurantInfo);

    getline(restaurantStream, restaurantName, ',');
    getline(restaurantStream, restaurantAdrress, ',');
    getline(restaurantStream, restaurantTelNumb, ',');
    getline(restaurantStream, restaurantOwner, ',');
}
restaurant::restaurant()
{
}

restaurant::~restaurant(){};

string restaurant::getRestaurantName()
{
    return restaurantName;
}
string restaurant::getRestaurantAdrress()
{
    return restaurantAdrress;
}
string restaurant::getRestaurantTelNumb()
{
    return restaurantTelNumb;
}
string restaurant::getRestaurantOwner()
{
    return restaurantOwner;
}

void restaurant::setRestaurantName(string name)
{
    restaurantName = name;
}

void restaurant::setRestaurantAdrress(string adrress)
{
    restaurantAdrress = adrress;
}

void restaurant::setRestauratTelNumber(string number)
{
    restaurantTelNumb = number;
}
void restaurant::setRestaurantOwner(string ownerName)
{
    restaurantOwner = ownerName;
}
string restaurant::getUserRestaurant(string username)
{

    fstream restaurantFile;
    string line;
    restaurantFile.open("data/restaurants.csv");
    //getline(restaurantFile, line); //skip first line
    if (restaurantFile.is_open())
    {
        while (getline(restaurantFile, line))
        {
            if (!(line.find(username) == string::npos))
            {
                restaurantFile.close();
                return line;
            }
        }
        return line;
    }
    else
    {
        cout << "Failed to open files";
        return line;
    }
}
int restaurant::updateRestaurant(string restaurantName, string newInfo)
{
    fstream fileIn, fileOut;
    string line;

    fileIn.open("data/restaurants.csv", ios::in);
    fileOut.open("data/newRestaurants.csv", ios::out | ios::app);

    if (fileIn.is_open() && fileOut.is_open())
    {
        while (getline(fileIn, line))
        {
            if (line.empty())
            {
                continue;
            }
            if (line.find(restaurantName) == string::npos)
            {

                fileOut << line << endl;
            }
            else
            {
                fileOut << newInfo << endl;
            }
        }
        fileIn.close();
        fileOut.close();

        remove("data/restaurants.csv");
        rename("data/newRestaurants.csv", "data/restaurants.csv");
        return EXIT_SUCCESS;
    }
    else
    {
        cout << "Failed to open files";
        return EXIT_FAILURE;
    }
}
//####################################################
//####################################################
restaurantList::restaurantList(/* args */)
{
    getRestaurantsData();
}

restaurantList::~restaurantList()
{
}

int restaurantList::getRestaurantsData()
{
    fstream restaurantData;
    string str, line;
    restaurants.clear();
    restaurantData.open("data/restaurants.csv");
    getline(restaurantData, str); //skip first line (headers)

    if (restaurantData.is_open())
    {
        while (getline(restaurantData, line))
        {
            if (line.empty())
            {
                continue;
            }

            restaurant r(line);
            restaurants.push_back(r);
        }
        restaurantData.close();
        return EXIT_SUCCESS;
    }
    else
    {
        cout << "Fail to opened file";
        return EXIT_FAILURE;
    }
}
vector<restaurant> restaurantList::getRestaurants()
{
    return restaurants;
}

int restaurant::insertRestaurant()
{
    fstream restaurantFile;

    restaurantFile.open("data/restaurants.csv", std::ios::in | std::ios::app);

    if (restaurantFile.is_open())
    {
        restaurantFile << restaurantName << ",";
        restaurantFile << restaurantAdrress << ",";
        restaurantFile << restaurantTelNumb << ",";
        restaurantFile << restaurantOwner << endl;

        restaurantFile.close();

        return EXIT_SUCCESS;
    }
    else
    {
        cout << "Fail to opened file";
        return EXIT_FAILURE;
    }
}

int restaurant::deleteRestaurant(string restaurantName)
{
    string line;
    fstream fileIn, fileOut;

    fileIn.open("data/restaurants.csv", ios::in);
    fileOut.open("data/restaurantsNew.csv", ios::out | ios::app);

    if (fileIn.is_open() && fileOut.is_open())
    {
        while (getline(fileIn, line))
        {
            if (line.find(restaurantName) == string::npos)
            {
                fileOut << line << endl;
            }
        }
        fileIn.close();
        fileOut.close();

        remove("data/restaurants.csv");
        rename("data/restaurantsNew.csv", "data/restaurants.csv");
        return EXIT_SUCCESS;
    }
    else
    {
        cout << "Fail to opened files";
        return EXIT_FAILURE;
    }
}

//####################################################