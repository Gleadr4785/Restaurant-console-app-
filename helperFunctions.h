
#include <vector>
#include <string>
#include <cctype>
#include "windows.h"
#include <iostream>
#include <fstream>
#include "restaurantClasses.h"
#include "reviewClasses.h"
#include "loginManager.h"

void gotoXY(int x, int y);
void menuHeader(std::string title);
void showMenuItems(std::vector<std::string> items);
void printRestaurant(std::string name, std::string adrress, std::string telNumb);
void printRestaurants(restaurantList *list);
void printReviews(reviewList *revs);
std::vector<std::string> getSearchedData(std::string fileName, std::string searchTerm);
std::string encryptDecrypt(std::string toEncrypt);
void noRestaurantMsg();
std::string getNewRestaurantInfo(std::string username);
std::string getAnswer();
std::string getReviewInfo(std::string username);
std::string getRestaurantInfo(std::string username);
std::string getRestaurantName();