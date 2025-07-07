#pragma once
#include <string>

class User{
    private:
        // replace with hashpassword for improved security
        std::string firstName, lastName;
        std::string validUsername, validEmail, validPassword;      

        // help function to read user data from file
        bool isUserdataValid(const std::string& targetUsername, std::string& foundEmail, std::string& foundPassword);
    
    public:
        void login();
        void signup();
        void forgot();

        // return username for bookManager
        std::string getLoggedInUser() const { return validUsername; }
};