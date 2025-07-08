#pragma once
#include <string>
#include <vector>
#include "Book.h"

class BookManager {
    private: 
        std::vector<Book> books;    // store books
        std::string currentUser;    // associate books with logged-in user
        std::string getBookFile() const;    // function that generates filename based on username

        // helper functions
        void loadBooks();
        void saveBooks();

        // function to get valid int input from user
        int getValidInt(const std::string& prompt);

    public:
        // constructor initialized with users username
        BookManager(const std::string& username);

        void showBooks() const;
        void addBook();
        void updateBook();
        void removeBook();

        // menu for book operations
        void bookMenu();
};