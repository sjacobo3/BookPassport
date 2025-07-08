#include <sstream>
#include "Book.h"

// constructor implementation
Book::Book(std::string& title, std::string& author, std::string& genre,
           const std::string& startDate, const std::string& endDate,
           int progress, int rating, const std::string& review)
    : title(title), author(author), genre(genre), startDate(startDate), endDate(endDate),
      progress(progress), rating(rating), review(review)
{
    // validate progress and rating
    setProgress(progress);
    setRating(rating);
}

void Book::setProgress(int p) {
    if (p < 0) progress = 0;
    else if (p > 100) progress = 100;
    else progress = p;
}

void Book::setRating(int r) {
    if (r < 1) rating = 1;
    else if (r > 5) rating = 5;
    else rating = r;
}

void Book::displayBook() const {
    std::cout << "\n---Book Details---" 
             << "\nTitle: " << title
             << "\nAuthor: " << author
             << "\nGenre: " << genre
             << "\nStart Date: " << startDate
             << "\nEnd Date: " << endDate
             << "\nProgress: " << progress << "%"
             << "\nRating: " << rating << "/5"
             << "\nReview: " << review
             << std::endl;
}

std::string Book::serialize() const {
    std::ostringstream oss;
    oss << title << "*" << author << "*" << genre << "*"
        << startDate << "*" << endDate << "*" << progress << "*" 
        << rating << "*" << review;
    return oss.str();
}

Book Book::deserialize(const std::string& data) {
    std::istringstream iss(data);
    std::string part;
    std::string title, author, genre, startDate, endDate, review;
    int progress = 0, rating = 0;

    // read parts separated by '*'
    getline(iss, title, '*');
    getline(iss, author, '*');
    getline(iss, genre, '*');
    getline(iss, startDate, '*');
    getline(iss, endDate, '*');
    
    // read progress
    if (!getline(iss, part, '*')) {
        std::cout << "Error reading progress, defaulting to 0.\n";
        progress = 0;
    }
    try { progress = std::stoi(part); } catch (...) { progress = 0; }

    // Read rating
    if (!getline(iss, part, '*')) { 
        std::cout << "Error reading rating, defaulting to 0.\n";
        rating = 0;
    }
    try { rating = std::stoi(part); } catch (...) { rating = 0; }

    // Read review - this should read till the end of the line
    if (!getline(iss, review)) { 
        std::cout << "Error reading review, defaulting to empty string.\n";
        review = "";
    } // Reads to end of line

    return Book(title, author, genre, startDate, endDate, progress, rating, review);
}