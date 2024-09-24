#include "LibraryHandlerApp.h"


// Constructor
LibraryHandlerApp::LibraryHandlerApp() : libraryManager() {}

// Display the main menu
void LibraryHandlerApp::displayMenu() const {
    std::cout << "\n=== Library Management System ===\n";
    std::cout << "1. Add Book\n";
    std::cout << "2. Add Borrower\n";
    std::cout << "3. Issue Book\n";
    std::cout << "4. Return Book\n";
    std::cout << "5. Display Inventory\n";
    std::cout << "6. Display Borrowers\n";
    std::cout << "7. Exit\n";
    std::cout << "Enter your choice: ";
}

// Handle adding a new book
void LibraryHandlerApp::handleAddBook() {
    int id;
    std::string title, author;
    std::cout << "Enter Book ID: ";
    std::cin >> id;
    std::cin.ignore();
    std::cout << "Enter Book Title: ";
    std::getline(std::cin, title);
    std::cout << "Enter Book Author: ";
    std::getline(std::cin, author);
    libraryManager.addBook(Book(id, title, author));
}

// Handle adding a new borrower
void LibraryHandlerApp::handleAddBorrower() {
    int id;
    std::string name;
    std::cout << "Enter Borrower ID: ";
    std::cin >> id;
    std::cin.ignore();
    std::cout << "Enter Borrower Name: ";
    std::getline(std::cin, name);
    libraryManager.addBorrower(Borrower(id, name));
}

// Handle issuing a book to a borrower
void LibraryHandlerApp::handleIssueBook() {
    int bookID, borrowerID;
    std::cout << "Enter Book ID to issue: ";
    std::cin >> bookID;
    std::cout << "Enter Borrower ID: ";
    std::cin >> borrowerID;
    libraryManager.issueBook(bookID, borrowerID);
}

// Handle returning a book
void LibraryHandlerApp::handleReturnBook() {
    int bookID, borrowerID;
    std::cout << "Enter Book ID to return: ";
    std::cin >> bookID;
    std::cout << "Enter Borrower ID: ";
    std::cin >> borrowerID;
    libraryManager.returnBook(bookID, borrowerID);
}

// Display all books in the inventory
void LibraryHandlerApp::handleDisplayInventory() const {
    libraryManager.displayInventory();
}

// Display all borrowers
void LibraryHandlerApp::handleDisplayBorrowers() const {
    libraryManager.displayBorrowers();
}

// Handle exiting the application
void LibraryHandlerApp::handleExit() const {
    std::cout << "Exiting Library Management System.\n";
}

// Run the main application loop
void LibraryHandlerApp::run() {
    int choice;
    do {
        displayMenu();
        std::cin >> choice;

        switch (choice) {
            case 1:
                handleAddBook();
                break;
            case 2:
                handleAddBorrower();
                break;
            case 3:
                handleIssueBook();
                break;
            case 4:
                handleReturnBook();
                break;
            case 5:
                handleDisplayInventory();
                break;
            case 6:
                handleDisplayBorrowers();
                break;
            case 7:
                handleExit();
                break;
            default:
                std::cout << "Invalid choice. Please try again.\n";
                break;
        }
    } while (choice != 7);
}
