#ifndef FRIENDMANAGER_H_INCLUDED
#define FRIENDMANAGER_H_INCLUDED

#include <iostream>
#include <stdexcept>
#include <string>
#include "DynamicArray.h"
#include "Map.h"
#include "GraphAdjList.h"
#include "PriorityQueue.h"

// User class declaration
class User {
public:
    int userID;
    std::string name;
    // Default constructor
    User();
    // Parameterized constructor
    User(int id, const std::string& userName);
    // Equality operator
    bool operator==(const User& other) const;

    int getUserID() const;
    std::string getName() const;
};

// Stream output operator for User
std::ostream& operator<<(std::ostream& os, const User& user);

// Friends class declaration
class FriendManager {
public:
    FriendManager();  // Default constructor
    FriendManager(int initialGraphSize);  // Parameterized constructor

    void addUser(const User& user);
    User getUserByID(int userID) const;
    void addFriendship(int userId1, int userId2);
    DynamicArray<int> recommendFriends(int userID);
    void display() const;
    void getRecommendations(int userID);
    void displayRelationships() const;
private:
    Map<int, User> userMap;  // Map to store users by their IDs
    GraphAdjList<int> friendGraph;  // Graph to represent friendships

    bool userExists(int userID) const;  // Helper function to check if a user exists in the map
};

#endif // FRIENDMANAGER_H_INCLUDED
