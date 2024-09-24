#ifndef LIBRARYMANAGER_H_INCLUDED
#define LIBRARYMANAGER_H_INCLUDED

#include "Book.h"
#include "Borrower.h"
#include "Map.h"
#include "PriorityQueue.h"
#include <iostream>

class LibraryManager {
public:
    LibraryManager();

    // Book and Borrower management
    void addBook(const Book& book);
    void addBorrower(const Borrower& borrower);
    Book& getBookByID(int bookID);
    Borrower& getBorrowerByID(int borrowerID);

    // Book issue and return functions
    void issueBook(int bookID, int borrowerID);
    void returnBook(int bookID, int borrowerID);

    // Display functions
    void displayInventory() const;
    void displayBorrowers() const;

    // New functions for handling overdue books
    void addOverdueBook(int bookID, int daysOverdue);
    void handleMostOverdueBook();

private:
    Map<int, Book> bookMap;
    Map<int, Borrower> borrowerMap;
    PriorityQueue<int> overdueQueue;

    bool bookExists(int bookID) const;
    bool borrowerExists(int borrowerID) const;

};


#endif // LIBRARYMANAGER_H_INCLUDED
