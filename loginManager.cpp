//#include "loginManager.h"
#include "helperFunctions.h"

using namespace std;

loginManager::loginManager(/* args */)
{
    accessGaranted = false;
}

loginManager::~loginManager()
{
}
string loginManager::getUsername()
{
    return username;
}
string loginManager::getRole()
{
    return role;
}
void loginManager::setUsername(string name)
{
    username = name;
}
void loginManager::setPassword(string pass)
{
    password = pass;
}
void loginManager::setRole(string rol)
{
    role = rol;
}
void loginManager::setUsernameAttempt(string name)
{
    passwordAttempt = name;
}
void loginManager::setPasswordAttempt(string pass)
{
    passwordAttempt = pass;
}
int loginManager::logIn()
{
    while (usernameAttempt.empty())
    {

        gotoXY(20, 5);
        cout << "Please enter your username : ";
        cin >> usernameAttempt;
    }
    vector<string> userData = getSearchedData("data/users.csv", usernameAttempt);

    if (userData.empty())
    {
        system("cls");
        gotoXY(20, 5);
        cout << "You are not registered yet.";
        cin.get();
        cin.get();
        return EXIT_SUCCESS;
    }

    setUsername(userData[0]);

    if (usernameAttempt == username)
    {

        while (passwordAttempt.empty())
        {
            gotoXY(20, 7);
            cout << "Please enter your password : ";
            cin >> passwordAttempt;
        }
        setPassword(encryptDecrypt(userData[1]));
        if (passwordAttempt == password)
        {
            setRole(userData[2]);
            gotoXY(20, 8);
            cout << "you are logged in";
            gotoXY(20, 10);
            cout << "Press Enter to go back to main menu";
            setUsernameAttempt(" ");
            setPasswordAttempt(" ");
            cin.get();
            cin.get();
            return EXIT_SUCCESS;
        }
        else
        {
            gotoXY(20, 5);
            cout << "Not even close ... ";
            gotoXY(20, 7);
            cout << "Press Enter to go back to main menu";
            cin.get();
            cin.get();
            logIn();
            return EXIT_FAILURE;
        }
    }
    return EXIT_SUCCESS;
}

int loginManager::signIn()
{
    fstream userFile;
    vector<string> userData;
    userFile.open("data/users.csv", std::ios::in | std::ios::app);

    if (!userFile.is_open())
    {
        cout << "Fail to opened file";
        return EXIT_FAILURE;
    }

    while (usernameAttempt.empty())
    {
        gotoXY(20, 5);
        cout << "Please enter your username : ";
        cin >> usernameAttempt;
    }
    userData = getSearchedData("data/users.csv", usernameAttempt);
    if (!userData.empty())
    {
        system("cls");
        gotoXY(20, 5);
        cout << "username already exist... ";
        gotoXY(20, 7);
        cout << "Press Enter to go back to main menu";
        cin.get();
        cin.get();
        return EXIT_SUCCESS;
    }

    while (passwordAttempt.empty())
    {
        gotoXY(20, 7);
        cout << "Please enter you password : ";
        cin >> passwordAttempt;
    }
    setUsername(usernameAttempt);
    setPassword(passwordAttempt);
    userFile << username << ",";
    userFile << encryptDecrypt(password) << ",";
    userFile << "user" << endl;
    gotoXY(20, 9);
    cout << "You successfully create your profile, now you can log In";
    gotoXY(20, 11);
    cout << "Press Enter to go back to main menu";
    cin.get();
    cin.get();
    userFile.close();
    setUsernameAttempt(" ");
    setPasswordAttempt(" ");

    return EXIT_SUCCESS;
}

int loginManager::logOut()
{
    setUsername(" ");
    setPassword(" ");
    setUsernameAttempt(" ");
    setPasswordAttempt(" ");
    setRole(" ");
    return EXIT_SUCCESS;
}

bool loginManager::isLoggedIn()
{
    return (!username.empty() && !password.empty() && !role.empty());
}