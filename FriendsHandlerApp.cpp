#include "FriendsHandlerApp.h"
#include <iostream>

// Constructor
FriendsHandlerApp::FriendsHandlerApp() :
    friendRel() {}

// Display the main menu
void FriendsHandlerApp::displayMenu() const {
    std::cout << "\n=== Friend Recommendation System Menu ===\n";
    std::cout << "1. Add User\n";
    std::cout << "2. Add Friendship\n";
    std::cout << "3. Display Users\n";
    std::cout << "4. Display Relationships\n";
    std::cout << "5. Recommend Friends\n";
    std::cout << "6. Exit\n";
    std::cout << "Enter your choice: ";
}

// Handle adding a new user
void FriendsHandlerApp::handleAddUser() {
    int id;
    std::string name;
    std::cout << "Enter User ID: ";
    std::cin >> id;
    std::cin.ignore();
    std::cout << "Enter User Name: ";
    std::getline(std::cin, name);
    friendRel.addUser(User(id, name));
}

// Handle adding a friendship
void FriendsHandlerApp::handleAddFriendship() {
    int userId1, userId2;
    std::cout << "Enter first User ID: ";
    std::cin >> userId1;
    std::cout << "Enter second User ID: ";
    std::cin >> userId2;
    friendRel.addFriendship(userId1, userId2);
}

// Handle displaying all users
void FriendsHandlerApp::handleDisplayUsers() const {
    std::cout << "\n=== Current Users ===\n";
    friendRel.display();
}

// Handle recommending friends
void FriendsHandlerApp::handleRecommendFriends()  {
    int userID;
    std::cout << "Enter User ID to get friend recommendations: ";
    std::cin >> userID;
    friendRel.getRecommendations(userID);
}

// Handle displaying user relationships
void FriendsHandlerApp::handleDisplayRelationships()  {
    std::cout << "\n=== User Relationships ===\n";
    friendRel.displayRelationships();
}

// Handle exiting the application
void FriendsHandlerApp::handleExit() const {
    std::cout << "Exiting Friend Recommendation System.\n";
}

// Main application loop
void FriendsHandlerApp::run() {
    int choice;
    do {
        displayMenu();
        std::cin >> choice;

        switch (choice) {
            case 1:
                handleAddUser();
                break;
            case 2:
                handleAddFriendship();
                break;
            case 3:
                handleDisplayUsers();
                break;
            case 4:
                handleDisplayRelationships();
                break;
            case 5:
                handleRecommendFriends();
                break;
            case 6:
                handleExit();
                break;
            default:
                std::cout << "Invalid choice. Please try again.\n";
                break;
        }
    } while (choice != 6);
}
