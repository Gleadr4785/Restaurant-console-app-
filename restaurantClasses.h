#ifndef RESTAURANTCLASSES_H
#define RESTAURANTCLASSES_H

#include <vector>
#include <string>
#include <sstream>
#include <fstream>
#include <iostream>

class restaurant
{
private:
    std::string restaurantName;
    std::string restaurantAdrress;
    std::string restaurantTelNumb;
    std::string restaurantOwner;

public:
    restaurant(std::string restaurantInfo);
    restaurant();
    ~restaurant();
    std::string getRestaurantName();
    std::string getRestaurantAdrress();
    std::string getRestaurantTelNumb();
    std::string getRestaurantOwner();
    void setRestaurantName(std::string name);
    void setRestaurantAdrress(std::string adrress);
    void setRestauratTelNumber(std::string Number);
    void setRestaurantOwner(std::string ownerName);
    std::string getUserRestaurant(std::string username);
    int updateRestaurant(std::string restaurantName, std::string newInfo);
    int insertRestaurant();
    int deleteRestaurant(std::string restaurantName);
};

class restaurantList
{
private:
    std::vector<restaurant> restaurants;

public:
    restaurantList(/* args */);
    ~restaurantList();
    int getRestaurantsData();
    std::vector<restaurant> getRestaurants();
};

#endif
