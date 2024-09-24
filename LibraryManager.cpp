#include "LibraryManager.h"

// Constructor
LibraryManager::LibraryManager() : bookMap(), borrowerMap() {}

// Adds a new book to the system
void LibraryManager::addBook(const Book& book) {
    if (!bookExists(book.getBookID())) {
        bookMap.add(book.getBookID(), book);
        std::cout << "Book added: " << book.getTitle() << std::endl;
    } else {
        std::cerr << "Book ID " << book.getBookID() << " already exists." << std::endl;
    }
}

// Retrieves a book by its ID
Book& LibraryManager::getBookByID(int bookID) {
    return bookMap.get(bookID);
}

// Adds a new borrower to the system
void LibraryManager::addBorrower(const Borrower& borrower) {
    if (!borrowerExists(borrower.getBorrowerID())) {
        borrowerMap.add(borrower.getBorrowerID(), borrower);
        std::cout << "Borrower added: " << borrower.getBorrowerID() << ", " << borrower.getName() << std::endl;
    } else {
        std::cerr << "Borrower ID " << borrower.getBorrowerID() << " already exists." << std::endl;
    }
}

// Retrieves a borrower by their ID
Borrower& LibraryManager::getBorrowerByID(int borrowerID) {
    return borrowerMap.get(borrowerID);
}

// Issues a book to a borrower
void LibraryManager::issueBook(int bookID, int borrowerID) {
    if (!bookExists(bookID) || !borrowerExists(borrowerID)) {
        std::cerr << "Error: Book or Borrower not found." << std::endl;
        return;
    }

    Book& book = bookMap.get(bookID);
    if (!book.getAvailability()) {
        std::cerr << "Book " << book.getTitle() << " is currently unavailable." << std::endl;
        return;
    }

    Borrower& borrower = borrowerMap.get(borrowerID);
    borrower.addLoan(bookID);
    book.setAvailability(false);

    std::cout << "Book issued to " << borrower.getName() << std::endl;
}

// Returns a book from a borrower

void LibraryManager::returnBook(int bookID, int borrowerID) {
    if (!bookExists(bookID) || !borrowerExists(borrowerID)) {
        std::cerr << "Error: Book or Borrower not found." << std::endl;
        return;
    }

    Book& book = bookMap.get(bookID);
    Borrower& borrower = borrowerMap.get(borrowerID);

    borrower.removeLoan(bookID);
    book.setAvailability(true);


    std::cout << "Book returned: " << book.getTitle() << std::endl;
}

// Display all books in the inventory
void LibraryManager::displayInventory() const {
    std::cout << "Library Inventory:\n";
    DynamicArray<Pair<int, Book>> books = bookMap.getAll();
    for (size_t i = 0; i < books.getSize(); ++i) {
        std::cout << books[i].value << std::endl;
    }
}

// Display all borrowers
void LibraryManager::displayBorrowers() const {
    std::cout << "Library Borrowers:\n";
    DynamicArray<Pair<int, Borrower>> borrowers = borrowerMap.getAll();
    std::cout << "Total borrowers: " << borrowers.getSize() << std::endl;
    for (size_t i = 0; i < borrowers.getSize(); ++i) {
        const Borrower& borrower = borrowers[i].value;
        std::cout << "Borrower ID: " << borrower.getBorrowerID()
                  << ", Name: " << borrower.getName() << ", ";
        borrower.printLoans();
    }
}

// Check if a book exists in the map
bool LibraryManager::bookExists(int bookID) const {
    try {
        bookMap.get(bookID);
        return true;
    } catch (const std::runtime_error&) {
        return false;
    }
}

// Check if a borrower exists in the map
bool LibraryManager::borrowerExists(int borrowerID) const {
    try {
        borrowerMap.get(borrowerID);
        return true;
    } catch (const std::runtime_error&) {
        return false;
    }
}

// Function to add an overdue book to the priority queue
void LibraryManager::addOverdueBook(int bookID, int daysOverdue) {
    if (!bookExists(bookID)) {
        std::cerr << "Book does not exist in the inventory." << std::endl;
        return;
    }
    overdueQueue.add(bookID, daysOverdue);
     // Add the book with priority based on days overdue
    std::cout << "Book ID: " << bookID
            << " added to the overdue queue with "
            << daysOverdue << " days overdue." << std::endl;
}

// Function to handle the most overdue book
void LibraryManager::handleMostOverdueBook() {
    if (overdueQueue.isEmpty()) {
        std::cout << "No overdue books to handle." << std::endl;
        return;
    }

    int mostOverdueBookID = overdueQueue.pop();  // Retrieve the most overdue book
    Book& overdueBook = getBookByID(mostOverdueBookID);
    std::cout << "Handling the most overdue book: " << overdueBook.getTitle() << std::endl;
}
