#include <iostream>
#include <fstream>
#include <string>
#include "BookManager.h"

using namespace std;

BookManager :: BookManager(const string& username) : currentUser(username) {
    // load books from file when manager is created
    loadBooks();
}

string BookManager :: getBookFile() const {
    return currentUser + "_books.txt";
}

void BookManager :: loadBooks() {
    books.clear();

    ifstream file(getBookFile());
    if (!file.is_open()) {
        cerr << "Error: Unable to open book file for user " << currentUser << endl;
        return;
    }

    string line;
    while(getline(file, line)) {
        try {
            books.push_back(Book::deserialize(line));
        } catch (const exception& e) {
            cerr << "Error loading book: " << e.what() << endl;
        }
    }
    file.close();
    cout << "Books loaded for " << currentUser << ".\n";
}

void BookManager :: saveBooks() {
    ofstream file(getBookFile());
    if (!file.is_open()) {
        cout << "Error: Could not save books for " << currentUser << ".\n";
        return;
    }

    for (const auto& book : books) {
        file << book.serialize() << endl;
    }
    file.close();
    cout << "Books saved for " << currentUser << ".\n";
}

void BookManager :: showBooks() const {
    if (books.empty()) {
        cout << "\nNo books currently logged for " << currentUser << ".\n";
        return;
    }

    cout << "\n---Books for " << currentUser << "---\n";
    for (size_t i = 0; i < books.size(); ++i) {
        cout << "\nBook #" << (i + 1) << ":\n";
        books[i].displayBook();
    }
    cout << "------------------------------\n";
}

void BookManager :: addBook() {
    string title, author, genre, startDate, endDate;

    cout << "\n---Add New Book---" 
         << "\nBook Title:";
    getline(cin, title);
    cout << "Author Name: ";
    getline(cin, author);
    cout << "Genre: ";
    getline(cin, genre);
    cout << "Start Date (MM-DD-YYYY or N/A): ";
    getline(cin, startDate);
    cout << "Finish Date (MM-DD-YYYY or N/A): ";
    getline(cin, endDate);

    books.emplace_back(title, author, genre, startDate, endDate, 0, 0, "");
    saveBooks();
    cout << "Book " << title << " added successfully!\n";
}

int BookManager :: getValidInt(const string& prompt) {
    int value;
    while (true) {
        cout << prompt;
        cin >> value;
        if (cin.fail()) {
            cout << "Invalid input. Please enter a number.\n";
            cin.clear(); // clear error flags
            cin.ignore('\n'); // ignore the rest of the line
        } else {
            cin.ignore('\n');
            return value;
        }
    }
}

void BookManager :: updateBook() {
    if (books.empty()) {
        cout << "\nNo books to update.\n";
    }

    showBooks();

    int bookIndex = getValidInt("\nEnter the book number to update: ");

    if (bookIndex < 1 || bookIndex > static_cast<int>(books.size())) {
        cout << "Invalid book number. Update cancelled.\n";
        return;
    }

    Book& bookToUpdate = books[bookIndex - 1];

    cout << "\n---Update Book Details---\n";
    cout << "Title: " << bookToUpdate.getTitle() << endl;
    cout << "Author: " << bookToUpdate.getAuthor() << endl;
    cout << "Genre: " << bookToUpdate.getGenre() << endl;
    
    cout << "Current Start Date: " << bookToUpdate.getStartDate() << "\nEnter new start date (or leave blank to keep current): ";
    string newStartDate;
    getline(cin, newStartDate);
    if (!newStartDate.empty()) bookToUpdate.setStartDate(newStartDate);

    cout << "Current End Date: " << bookToUpdate.getEndDate() << "\nEnter new end date (or leave blank to keep current): ";
    string newEndDate;
    getline(cin, newEndDate);
    if (!newEndDate.empty()) bookToUpdate.setStartDate(newEndDate);

    cout << "Enter new Progress (0-100, current: " << bookToUpdate.getProgress() << "%): ";
    string newProgressStr;
    getline(cin, newProgressStr);
    if (!newProgressStr.empty()) {
        try {
            int newProgress = stoi(newProgressStr);
            bookToUpdate.setProgress(newProgress);
        } catch (const exception& e) {
            cout << "Invalid progress input. Keeing orginal.\n";
        }
    }

    cout << "Enter new rating (0-5, current: " << bookToUpdate.getRating() << "): ";
    string newRatingStr;
    getline(cin, newRatingStr);
    if (!newRatingStr.empty()) {
        try {
            int newRating = stoi(newRatingStr);
            bookToUpdate.setProgress(newRating);
        } catch (const exception& e) {
            cout << "Invalid rating input. Keeing orginal.\n";
        }
    }

    saveBooks();
    cout << "\nBook updated successfully!\n";
}

void BookManager::removeBook() {
    if (books.empty()) {
        cout << "\nNo books to remove.\n";
        return;
    }

    showBooks();
    int bookIndex = getValidInt("Enter the number of the book to remove: ");

    if (bookIndex < 1 || bookIndex > static_cast<int>(books.size())) {
        cout << "Invalid book number.\n";
        return;
    }

    string removedTitle = books[bookIndex - 1].getTitle();
    // erase the book from the vector
    books.erase(books.begin() + bookIndex - 1);
    saveBooks();
    cout << "\nBook " << removedTitle << " removed successfully!\n";
}

void BookManager :: bookMenu() {
    char choice;
    while (choice != '5') {
        cout << "\n--- Book Management Menu (" << currentUser << ") ---";
        cout << "\n1 - Show all your books";
        cout << "\n2 - Add a new book";
        cout << "\n3 - Update a book";
        cout << "\n4 - Remove a book";
        cout << "\n5 - Logout / Return to Main Menu";
        cout << "\nPlease choose an option: ";

        cin >> choice;
        cin.ignore('\n');

        switch (choice) {
            case '1':
                showBooks();
                break;
            case '2':
                addBook();
                break;
            case '3':
                updateBook();
                break;
            case '4':
                removeBook();
                break;
            case '5':
                cout << "\nLogging out from book management...\n";
                break;
            default:
                cout << "Invalid selection. Please try again.";
                break;
        }
    }
};