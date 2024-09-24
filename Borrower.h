#ifndef BORROWER_H_INCLUDED
#define BORROWER_H_INCLUDED

#include <string>
#include "DynamicArray.h"
#include <iostream>

class Borrower {
private:
    int borrowerID;
    std::string name;
     // List of book IDs currently loaned
    DynamicArray<int> loanHistory;
public:


    // Default constructor
    Borrower();
    // Parameterized constructor
    Borrower(int id, const std::string& borrowerName);

    // Equality operator
    bool operator==(const Borrower& other) const;

    // Getters
    int getBorrowerID() const;
    std::string getName() const;

    // Loan management
    void addLoan(int bookID);
    void removeLoan(int bookID);
    bool isOverdue() const;
    void printLoans() const;

    // Overloaded stream output operator
    friend std::ostream& operator<<(std::ostream& os,
                            const Borrower& borrower);
};

#endif // BORROWER_H_INCLUDED
