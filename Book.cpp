#include "Book.h"

// Default constructor
Book::Book() : bookID(0),
    title(""), author(""),
    isAvailable(true) {}

// Parameterized constructor
Book::Book(int id, const std::string& bookTitle,
           const std::string& bookAuthor)
    : bookID(id), title(bookTitle), author(bookAuthor),
        isAvailable(true) {}

// Equality operator
bool Book::operator==(const Book& other) const {
    return bookID == other.bookID;
}

// Getters
int Book::getBookID() const {
    return bookID;
}

std::string Book::getTitle() const {
    return title;
}

std::string Book::getAuthor() const {
    return author;
}

bool Book::getAvailability() const {
    return isAvailable;
}

// Setter for availability
void Book::setAvailability(bool status) {
    isAvailable = status;
}

// Overloaded stream output operator
std::ostream& operator<<(std::ostream& os, const Book& book) {
    os << "Book ID: " << book.bookID
       << ", Title: " << book.title
       << ", Author: " << book.author
       << ", Available: " << (book.isAvailable ? "Yes" : "No");
    return os;
}
