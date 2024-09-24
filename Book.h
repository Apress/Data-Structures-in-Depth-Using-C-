#ifndef BOOK_H_INCLUDED
#define BOOK_H_INCLUDED

#include <string>
#include <iostream>

class Book {
public:
    int bookID;
    std::string title;
    std::string author;
    bool isAvailable;

    // Default constructor
    Book();
    // Parameterized constructor
    Book(int id,
         const std::string& bookTitle,
         const std::string& bookAuthor);

    // Equality operator
    bool operator==(const Book& other) const;

    // Getters
    int getBookID() const;
    std::string getTitle() const;
    std::string getAuthor() const;
    bool getAvailability() const;

    // Setter for availability
    void setAvailability(bool status);

    // Overloaded stream output operator
    friend std::ostream& operator<<(std::ostream& os,
                                    const Book& book);
};



#endif // BOOK_H_INCLUDED
