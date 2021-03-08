#include "reviewClasses.h"
#include "helperFunctions.h"
using namespace std;
//###################################
review::review(string reviewInfo)
{
    stringstream reviewsStream(reviewInfo);

    getline(reviewsStream, author, ',');
    getline(reviewsStream, restaurantName, ',');
    getline(reviewsStream, points, ',');
    getline(reviewsStream, reviewText);
}
review::review()
{
}
review::~review()
{
}
string review::getAuthor()
{
    return author;
}
string review::getRestaurantName()
{
    return restaurantName;
}
string review::getReviewText()
{
    return reviewText;
}
string review::getPoints()
{
    return points;
}
void review::setAuthor(string username)
{
    author = username;
}
void review::setRestaurantName(string name)
{
    restaurantName = name;
}
void review::setReviewText(std::string text)
{
    reviewText = text;
}
void review::setPoints(int n)
{
    points = n;
}
int review::insertReview()
{

    fstream reviewsFile;

    reviewsFile.open("data/reviews.csv", ios::out | ios::app);

    if (reviewsFile.is_open())
    {
        reviewsFile << author << ",";
        reviewsFile << restaurantName << ",";
        reviewsFile << reviewText << ",";
        reviewsFile << points;
        reviewsFile << endl;

        reviewsFile.close();
        return EXIT_SUCCESS;
    }
    else
    {
        cout << "Fail to opened file";
        return EXIT_FAILURE;
    }

    return EXIT_SUCCESS;
}
//###################################
//###################################

reviewList::reviewList(/* args */)
{
}

reviewList::~reviewList()
{
}

vector<review> reviewList::getReviews()
{
    return reviews;
}

int reviewList::getReviewsData()
{
    fstream reviewsFile;
    string str, line;
    reviews.clear();
    reviewsFile.open("data/reviews.csv");
    getline(reviewsFile, str); //skip first line (header of csv)

    if (reviewsFile.is_open())
    {
        while (getline(reviewsFile, line))
        {
            if (line.empty())
            {
                continue;
            }

            review r(line);
            reviews.push_back(r);
        }
        reviewsFile.close();
        return EXIT_SUCCESS;
    }
    else
    {
        cout << "Fail to opened file";
        return EXIT_FAILURE;
    }
}

int reviewList::getReviewByRestaurantOwner(string name)
{
    fstream reviewsFile;
    string line;
    reviews.clear();
    reviewsFile.open("data/reviews.csv");

    if (reviewsFile.is_open())
    {
        while (getline(reviewsFile, line))
        {
            if (line.empty())
            {
                continue;
            }
            if (!name.empty())
            {
                if (!(line.find(name) == string::npos))
                {
                    review r(line);
                    reviews.push_back(r);
                }
            }
        }
        reviewsFile.close();
        return EXIT_SUCCESS;
    }
    else
    {
        cout << "Fail to opened file";
        return EXIT_FAILURE;
    }
}

int reviewList::getReviewsByRestaurantName(string rName)
{
    fstream reviewsFile;
    string line;
    reviews.clear();
    reviewsFile.open("data/reviews.csv");

    if (reviewsFile.is_open())
    {
        while (getline(reviewsFile, line))
        {
            if (line.empty())
            {
                continue;
            }
            if (!rName.empty())
            {
                if (!(line.find(rName) == string::npos))
                {
                    review r(line);
                    reviews.push_back(r);
                }
            }
        }
        reviewsFile.close();
        return EXIT_SUCCESS;
    }
    else
    {
        cout << "Fail to opened file";
        return EXIT_FAILURE;
    }
    if (reviews.empty())
    {
        system("cls");
        gotoXY(20, 5);
        cout << "Searched restaurant doesn't exist yet ... ";
        return EXIT_FAILURE;
    }
}
//###################################