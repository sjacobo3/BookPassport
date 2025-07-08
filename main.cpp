#include <iostream>
#include "User.h"
#include "BookManager.h"

int main() {
    User user;
    std::string loggedInUser;
    char choice;

    while (true) {
        // display menu options
        if (user.loginFlag) {
            loggedInUser = user.getUsername();
            std::cout << "\nCurrently logged in as: " << loggedInUser;
            std::cout << "\n1 - Forgot Password";
            std::cout << "\n2 - Go to Book Management";
            std::cout << "\n3 - Logout";
            std::cout << "\n4 - Exit Program";
        } else {
            std::cout << "\nWelcome! Log in or register to get started.";
            std::cout << "\n1 - Login";
            std::cout << "\n2 - Register";
            std::cout << "\n3 - Forgot Password";
            std::cout << "\n4 - Exit Program";
        } 

        std::cout << "\nPlease choose an option: ";
        std::cin >> choice;
        std::cin.ignore(); // clear the newline character 

        switch(choice) {
            case '1': {
                if (!user.loginFlag) {
                    if (user.login()) {
                        user.loginFlag = true;
                        loggedInUser = user.getUsername();
                    } 
                } else {
                    // user is logged in, first option is to get lost password
                    user.forgot();
                }
                break;
            }
            case '2':
                if (!user.loginFlag) {
                    user.signup();
                } else {
                    // user logged in, will go to book management system
                    BookManager bookManager(loggedInUser);
                    bookManager.bookMenu();
                }
                break;
            case '3':
                if (!user.loginFlag) {
                    // user not logged in, forgot password function
                    user.forgot();
                } else {
                    // logging out user
                    user.loginFlag = false;
                    loggedInUser = "";  // clear username
                    std::cout << "\nLogged out successfully.\n";
                }
                break;
            case '4': 
                std::cout << "\nExiting program. Goodbye!\n";
                return 0;
                break;
            default: 
                std::cout << "Invalid selection. Please try again.\n";
                break;
        }
    }

    return 0;
}

