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
            std::cout << "\nCurrently logged in as: " << loggedInUser << std::endl;
            std::cout << "\n1 - Forgot/Change Password";
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
                if (user.login()) {
                    user.loginFlag = true;
                    loggedInUser = user.getUsername();
                    std::cout << "\nWelcome " << user.getUsername() << "! You are now logged in" << std::endl;
                    std::cout << "Returning to main menu.\n";
                }
                break;
            }
            case '2':
                user.signup();
                break;
            case '3':
                user.forgot();
                break;
            case '4': 
                if (user.loginFlag) {
                    // go to book management
                    BookManager bookManager(loggedInUser);
                    bookManager.bookMenu();
                } else {
                    std::cout << "\nExiting program. Goodbye!\n";
                    return 0;
                }
                break;
            case '5':
                if (user.loginFlag) {
                    // logging user out
                    user.loginFlag = false;
                    loggedInUser = "";
                    std::cout << "\nLogged out successfully.\n";
                } else {
                    std::cout << "Invalid selection. Please try again.\n";
                }
                break;
            case '6':
                if (user.loginFlag) {
                    std::cout << "\nExiting program. Goodbye!\n";
                    return 0;
                } else {
                    std::cout << "Invalid selection. Please try again.\n";
                }
                break;
            default: 
                std::cout << "Invalid selection. Please try again.\n";
                break;
        }
    }

    return 0;
}

