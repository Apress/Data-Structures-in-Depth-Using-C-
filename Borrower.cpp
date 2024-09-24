#include "Borrower.h"
// Default constructor
Borrower::Borrower() : borrowerID(0), name(""), loanHistory() {}
Borrower::Borrower(int id, const std::string& borrowerName)
    : borrowerID(id), name(borrowerName),loanHistory() {}

// Equality operator
bool Borrower::operator==(const Borrower& other) const {
    return borrowerID == other.borrowerID;
}

// Getters
int Borrower::getBorrowerID() const {
    return borrowerID;
}

std::string Borrower::getName() const {
    return name;
}

// Loan management
void Borrower::addLoan(int bookID) {
    // Prevent duplicate loan entries
    if (loanHistory.indexOf(bookID) == -1) {
        loanHistory.pushBack(bookID);
    }
}

void Borrower::removeLoan(int bookID) {
   // Safely remove the loan if it exists
    int index = loanHistory.indexOf(bookID);
    if (index != -1) {
        loanHistory.removeAt(index);
    } else {
        std::cerr << "Error: Attempting to remove non-existent loan." << std::endl;
    }
}

bool Borrower::isOverdue() const {
    // Implement overdue checking logic if required
    return false;
}

void Borrower::printLoans() const {
    if (loanHistory.getSize() > 0) {
        std::cout << "Loans: ";
        for (size_t i = 0; i < loanHistory.getSize(); ++i) {
            std::cout << loanHistory[i] << " ";
        }
        std::cout << std::endl;
    } else {
        std::cout << "Loans: None" << std::endl;
    }
}

// Overloaded stream output operator
std::ostream& operator<<(std::ostream& os, const Borrower& borrower) {
    os << "Borrower ID: " << borrower.borrowerID
       << ", Name: " << borrower.name
       << ", Loans: ";
    for (size_t i = 0; i < borrower.loanHistory.getSize(); ++i) {
        os << borrower.loanHistory.get(i) << " ";
    }
    return os;
}
