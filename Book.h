#pragma once
#include <string>
#include <iostream>

class Book {
    private: 
        std::string title, author, genre;
        std::string startDate, endDate;
        int progress; // percentage of completion
        int rating; // 1 to 5 stars
        std::string review; // personal notes about the book
    public:
        // constructor to create Book objects
        Book(std::string& t, std::string& a, std::string& g, 
             const std::string& sd = "N/A", const std::string& ed = "N/A", 
             int p = 0, int r = 0, const std::string& rev = "" );

        // getter methods for displaying book info
        std::string getTitle() const { return title;}
        std::string getAuthor() const { return author; }
        std::string getGenre() const { return genre; }
        std::string getStartDate() const { return startDate; }
        std::string getEndDate() const { return endDate; }
        int getProgress() const { return progress; }
        int getRating() const { return rating; }
        std::string getReview() { return review; }

        // setter to allow for changing after creating a Book object
        void setStartDate(const std::string& date) { startDate = date; }
        void setEndDate(const std::string& date) { endDate = date; }
        void setProgress(int p);
        void setRating(int r);
        void setReview(const std::string& rev) { review = rev; }

        // method to display a single book's details
        void displayBook() const;

        // serialization method to convert book data to a string for saving
        std::string serialize() const;
        // static method to deserialize a string back into a Book object
        static Book deserialize(const std::string& data);
};

