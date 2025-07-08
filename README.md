# 📚 BookPassport

## table of contents
- about the project
- features
- getting started
- usage
- future enhancements

## about the project
This project is a command-line interface (CLI) application developed in C++ that allows users to manage their personal book collection. It features a basic authentication system (registration, login, password recovery) to ensure that each user's data is kept separate;

Once logged in, users can:
- Add new books with details like title, author, genre, start/end dates, reading progress, rating, and a personal review.
- View all their logged books.
- Update existing book details.
- Remove books from their collection.
Currently, all user and book data is persistently stored in text files.

## features
- User Authentication:
  - Register new user accounts.
  - Log in to existing accounts.
  - Recover forgotten passwords (by providing username and email).
- Personalized Book Management:
  - Add Books: Record comprehensive details for each book.
  - View Books: Display a list of all books in a user's collection.
  - Update Books: Modify details of existing book entries.
  - Remove Books: Delete books from the collection.
 
## getting started
To get a local copy up and running, follow the steps:
### prerequisites
You'll need a C++ compiler installed on your system
* g++ (Linux/macOS):
    ```sh
    # on Debian/Ubuntu
    sudo apt update
    sudo apt install build-essential
    
    # on macOS with Homebreq
    brew install gcc
    ```
### installation
1. clone the repo:
   ```sh
   git clone https://github.com/sjacobo3/BookPassport.git
   cd BookPassport
   ```
2. compile the project using the Makefile
   ```sh
   make
   ```
   this command compiles all the source files and creates an executable ```my_book_app```.

## usage
After successful compilation, run the application from your terminal:
```sh
./book_passport
```
The program presents you with a main menu:
1. Login: Access your existing account.
2. Register: Create a new user account.
3. Forgot Password: Recover your password using your username and email.
4. Exit Program: Close the application.
Once logged in, you'll be taken to the Book Management Menu where you can perform operations on your personal book collection.

## future enhancements
- plan on improving security by implementing strong password hashing instead of plan text storage.
- want to enhance user interface to be more interactive.
- will be implementing an advanced search/filter for users to sort books by various criteria.
- better user storage using a backend system.
