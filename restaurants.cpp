
#include "helperFunctions.h"

using namespace std;
int main()
{
    reviewList *revs;
    loginManager *app;

    bool running = true;
    int x = 8;
    int menuItem = 1;

    string choice;
    string newInfo;
    review *rev;
    restaurant *userRestaurant;
    reviewList *userRestaurantReviews;
    restaurantList *restaurants;

    while (running)
    {

        system("cls");
        //display header;
        menuHeader("RESTAURANT APP");
        //display main menu
        if (app->isLoggedIn() && (app->getRole() == "user"))
        {
            userRestaurant = new restaurant(userRestaurant->getUserRestaurant(app->getUsername()));
            showMenuItems({"Show all restaurants", "Show all reviews", "Show reviews of my restuarant", "Write review", "Add Restaurant", "Delete my restaurant", "Edit my restaurant", "Log Out", "Exit application"});
            //display arrow navigator
            gotoXY(22, x);
            cout << "->";

            system("pause>nul");
            //arrow up event
            if ((GetAsyncKeyState(VK_DOWN) & 0x8000) && (x != 16))
            {
                gotoXY(22, x);
                cout << "  ";
                x++;
                gotoXY(22, x);
                cout << "->";
                menuItem++;
                continue;
            }
            //arrow down event
            if ((GetAsyncKeyState(VK_UP) & 0x8000) && (x != 8))
            {
                gotoXY(22, x);
                cout << "  ";
                x--;
                gotoXY(22, x);
                cout << "->";
                menuItem--;
                continue;
            }
            if (GetAsyncKeyState(VK_RETURN) & 0x8000)
            {
                switch (menuItem)
                {
                case 1:
                    system("cls");
                    restaurants = new restaurantList;
                    restaurants->getRestaurantsData(); //get actuall data (not from constructor)
                    printRestaurants(restaurants);
                    delete restaurants;
                    cin.get();
                    break;
                case 2:
                    system("cls");
                    revs = new reviewList;
                    revs->getReviewsData();
                    printReviews(revs);
                    delete revs;
                    cin.get();
                    break;
                case 3:
                    system("cls");
                    userRestaurantReviews = new reviewList;
                    userRestaurantReviews->getReviewByRestaurantOwner(userRestaurant->getRestaurantName());
                    if (userRestaurant->getRestaurantName().empty())
                    {
                        noRestaurantMsg();
                        break;
                    }
                    if (userRestaurantReviews->getReviews().empty())
                    {
                        gotoXY(20, 5);
                        cout << "Your restaurant doesn't have reviews ... ";
                    }
                    printReviews(userRestaurantReviews);
                    delete userRestaurantReviews;
                    cin.get();
                    break;
                case 4:
                    system("cls");
                    rev = new review(getReviewInfo(app->getUsername()));
                    if (userRestaurant->getRestaurantName() == rev->getRestaurantName())
                    {
                        system("cls");
                        gotoXY(20, 5);
                        cout << "You can't write review of your restaurant ... ";
                        cin.get();
                        break;
                    }
                    rev->insertReview();
                    cin.get();
                    delete rev;
                    break;
                case 5:
                    system("cls");
                    if (!userRestaurant->getRestaurantName().empty())
                    {
                        gotoXY(20, 5);
                        cout << "You can have only one restaurant in our system ... :) ";
                        gotoXY(20, 7);
                        cout << "Press enter to back to main menu";
                        cin.get();
                        break;
                    }
                    userRestaurant = new restaurant(getRestaurantInfo(app->getUsername()));
                    userRestaurant->insertRestaurant();
                    break;
                case 6:

                    while (true)
                    {
                        system("cls");
                        if (userRestaurant->getRestaurantName().empty())
                        {
                            noRestaurantMsg();
                            break;
                        }
                        gotoXY(20, 5);
                        choice = getAnswer();
                        if (choice == "y")
                        {
                            userRestaurant->deleteRestaurant(userRestaurant->getRestaurantName());
                            delete userRestaurant;
                            break;
                        }
                        else if (choice == "n")
                        {
                            break;
                        }
                    }

                    break;
                case 7:
                    system("cls");
                    if (userRestaurant->getRestaurantName().empty())
                    {
                        noRestaurantMsg();
                        break;
                    }
                    printRestaurant(userRestaurant->getRestaurantName(), userRestaurant->getRestaurantAdrress(), userRestaurant->getRestaurantTelNumb());
                    while (true)
                    {
                        gotoXY(20, 13);
                        choice = getAnswer();
                        if (choice == "y")
                        {
                            newInfo = getNewRestaurantInfo(app->getUsername());
                            while (true)
                            {
                                gotoXY(20, 21);
                                choice = getAnswer();
                                if (choice == "y")
                                {
                                    userRestaurant->updateRestaurant(userRestaurant->getRestaurantName(), newInfo);
                                    break;
                                }
                                else if (choice == "n")
                                {
                                    break;
                                }
                            }
                            break;
                        }
                        else if (choice == "n")
                        {
                            break;
                        }
                    }

                    break;
                case 8:
                    system("cls");
                    app->logOut();
                    delete app;
                    x = 8;
                    menuItem = 1;
                    delete userRestaurant;
                    break;
                case 9:
                    system("cls");
                    delete userRestaurant;
                    running = false;
                    break;
                }
            }
        }
        else
        {

            showMenuItems({
                "Show all restaurants",
                "Show all reviews",
                "Show reviews by restaurant name",
                "Log In",
                "Sing in",
                "Exit application",
            });
            //display arrow navigator
            gotoXY(22, x);
            cout << "->";

            system("pause>nul");
            //arrow up event
            if ((GetAsyncKeyState(VK_DOWN) & 0x8000) && (x != 13))
            {
                gotoXY(22, x);
                cout << "  ";
                x++;
                gotoXY(22, x);
                cout << "->";
                menuItem++;
                continue;
            }
            //arrow down event
            if ((GetAsyncKeyState(VK_UP) & 0x8000) && (x != 8))
            {
                gotoXY(22, x);
                cout << "  ";
                x--;
                gotoXY(22, x);
                cout << "->";
                menuItem--;
                continue;
            }
            if (GetAsyncKeyState(VK_RETURN) & 0x8000)
            {
                switch (menuItem)
                {
                case 1:
                    system("cls");
                    restaurants = new restaurantList;
                    restaurants->getRestaurantsData(); //get actuall data (not from constructor)
                    printRestaurants(restaurants);
                    delete restaurants;
                    cin.get();
                    break;
                case 2:
                    system("cls");
                    revs = new reviewList;
                    revs->getReviewsData();
                    printReviews(revs);
                    delete revs;
                    cin.get();
                    break;
                case 3:
                    system("cls");
                    revs = new reviewList;
                    revs->getReviewsByRestaurantName(getRestaurantName());
                    if (revs->getReviews().empty())
                    {
                        gotoXY(20, 5);
                        cout << "Wrong input or restaurant doesn't exist";
                    }
                    printReviews(revs);
                    delete revs;
                    cin.get();
                    break;
                case 4:
                    system("cls");
                    app = new loginManager;
                    app->logIn();
                    break;
                case 5:
                    system("cls");
                    app = new loginManager;
                    app->signIn();
                    break;
                case 6:
                    system("cls");
                    running = false;
                    break;
                }
            }
        }
    }
    return EXIT_SUCCESS;
}
