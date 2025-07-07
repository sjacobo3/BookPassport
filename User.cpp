#include <iostream>
#include <fstream>
#include "User.h"

using namespace std;

void User :: signup() {
    cout << "\nEnter your first name: ";
    getline(cin, firstName);

    cout << "Enter your last name: ";
    getline(cin, lastName);

    cout << "Enter your Username: ";
    getline(cin, validUsername);

    cout << "Enter your Email: ";
    getline(cin, validEmail);

    cout << "Enter your Password: ";
    getline(cin, validPassword);

    // save data
    ofstream file("loginData.txt", ios::app);
    if (!file.is_open()) {
        cout << "Error: Could not open file for writing.\n";
        return;
    }
    file << validUsername << "*" << validEmail << "*" << validPassword << endl;
    file.close();
    cout << "\nRegistration successful!\n" << endl;
}

bool User :: isUserdataValid(const string& targetUsername, string& foundEmail, string& foundPassword) {
    // read in user data from file
    ifstream file("loginData.txt");
    if (!file.is_open()) {
        cout << "Error: Could not open user data file.\n";
        return false;
    }

    string line;
    while(getline(file, line)) {
        size_t pos1 = line.find('*');
        size_t pos2 = line.find('*', pos1 + 1);

        string storedUsername = line.substr(0, pos1);
        string storedEmail = line.substr(pos1 + 1, pos2 - pos1 - 1);
        string storedPassword = line.substr(pos2 + 1);

        if (storedUsername == targetUsername) {
            foundEmail = storedEmail;
            foundPassword = storedPassword;
            file.close();
            return true;        // user found
        }
    }
    file.close();
    // If we reach here, the username was not found
    return false;
}

void User :: login() {
    // prompt user to login, storing variables to look for in file
    string searchUser, searchPass;
    cout << "\nEnter your Username: ";
    getline(cin, searchUser);
    
    cout << "Enter your Password: ";
    getline(cin, searchPass);

    string foundEmail, foundPassword;
    // check if user data is valid
    if (isUserdataValid(searchUser, foundEmail, foundPassword)) {
        if (searchPass == foundPassword) {
            cout << "\nLogin successful! Welcome, " << firstName << " " << lastName << "!" << endl;
            return; // Exit after successful login
        } else {
            cout << "\nIncorrect password. Please try again." << endl;
            return; // Exit after failed password attempt
        }
    } else {
        cout << "\nUsername not found. Please check your username or register if you don't have an account." << endl;
    }
}

void User :: forgot() {
    string searchUser, searchEmail;
    cout << "\nEnter your Username: ";
    getline(cin, searchUser);
    cout << "Enter your Email: ";
    getline(cin, searchEmail);

    string foundEmail, foundPassword;
    if (isUserdataValid(searchUser, foundEmail, foundPassword)) {
        if (searchEmail == foundEmail) {
            cout << "\nPassword recovery successful!" << endl;
            cout << "Your password is: " << foundPassword << endl;
        } else {
            cout << "\nEmail does not match our records for this username." << endl;
        }
    } else {
        cout << "\nUsername not found. Please check your username or register if you don't have an account.\n";
    }
}