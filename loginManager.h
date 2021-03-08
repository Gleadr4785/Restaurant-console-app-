#ifndef LOGINMANAGAER_H
#define LOGINMANAGER_H

#include <string>
#include <iostream>
#include <fstream>

class loginManager
{
private:
    std::string username;
    std::string password;
    std::string role;
    std::string usernameAttempt;
    std::string passwordAttempt;
    bool accessGaranted;

public:
    loginManager(/* args */);
    ~loginManager();
    std::string getUsername();
    std::string getRole();
    int logIn();
    int signIn();
    int logOut();
    void setUsername(std::string name);
    void setPassword(std::string pass);
    void setRole(std::string rol);
    void setUsernameAttempt(std::string name);
    void setPasswordAttempt(std::string pass);
    bool isLoggedIn();
};

#endif