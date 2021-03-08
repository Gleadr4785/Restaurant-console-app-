#ifndef REVIEWCLASSES_H
#define REVIEWCLASSES_H

#include <string>
#include <sstream>
#include <vector>
#include <fstream>
#include <iostream>

class review
{
private:
    std::string author;
    std::string restaurantName;
    std::string reviewText;
    std::string points;

public:
    review(std::string reviewInfo);
    review();
    ~review();

    std::string getAuthor();
    std::string getRestaurantName();
    std::string getReviewText();
    void setAuthor(std::string username);
    void setRestaurantName(std::string name);
    void setReviewText(std::string text);
    void setPoints(int n);
    std::string getPoints();
    int insertReview();
};

class reviewList
{
private:
    std::vector<review> reviews;

public:
    reviewList(/* args */);
    ~reviewList();

    int getReviewsData();
    int getReviewByRestaurantOwner(std::string name);
    int getReviewsByRestaurantName(std::string rName);
    std::vector<review> getReviews();
};

#endif
