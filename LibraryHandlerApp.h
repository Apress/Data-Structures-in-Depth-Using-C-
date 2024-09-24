#ifndef LIBRARYHANDLERAPP_H_INCLUDED
#define LIBRARYHANDLERAPP_H_INCLUDED

#include "LibraryManager.h"
#include <iostream>

class LibraryHandlerApp {
public:
    LibraryHandlerApp();

    void displayMenu() const;
    void handleAddBook();
    void handleAddBorrower();
    void handleIssueBook();
    void handleReturnBook();
    void handleDisplayInventory() const;
    void handleDisplayBorrowers() const;
    void handleExit() const;
    void run();

private:
    LibraryManager libraryManager;
};

#endif // LIBRARYHANDLERAPP_H_INCLUDED
