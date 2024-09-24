#include "FriendManager.h"
#include <iostream>
// User class implementation
User::User() : userID(0), name("Unknown") {}

User::User(int id, const std::string& userName) : userID(id), name(userName) {}

bool User::operator==(const User& other) const {
    return userID == other.userID;
}

int User::getUserID() const {
    return userID;
}

std::string User::getName() const {
    return name;
}

// Stream output operator for User
std::ostream& operator<<(std::ostream& os, const User& user) {
    os << "User ID: " << user.userID << ", Name: " << user.name;
    return os;
}

// FriendRecommendation class implementation
FriendManager::FriendManager()
    : userMap(), friendGraph(1) {}

FriendManager::FriendManager(int initialGraphSize)
    : userMap(), friendGraph(initialGraphSize) {}


void FriendManager::addUser(const User& user) {
    if (!userExists(user.getUserID())) {
        userMap.add(user.getUserID(), user);
        friendGraph.addVertex();
    } else {
        std::cerr << "User ID " << user.getUserID() << " already exists." << std::endl;  // Using cerr for error-like messages
    }
}


void FriendManager::addFriendship(int userId1, int userId2) {
    if (!userExists(userId1) || !userExists(userId2)) {
        std::cerr << "Error: One or both users do not exist." << std::endl;
        return;
    }

    try {
        friendGraph.addEdge(userId1, userId2);  // Add edge in one direction
        friendGraph.addEdge(userId2, userId1);  // Add edge in the opposite direction
        std::cout << "Added friendship between " << userId1 << " and " << userId2 << std::endl;
    } catch (const std::exception& e) {
        std::cerr << "Graph Error: " << e.what() << std::endl;
    }
}

DynamicArray<int> FriendManager::recommendFriends(int userID) {
    DynamicArray<int> recommendations;

    // Check if the user exists
    if (!userExists(userID)) {
        std::cerr << "User ID not found for recommendations." << std::endl;
        return recommendations;  // Return empty recommendations if the user doesn't exist
    }

    // Get the direct friends of the user from the friend graph
    DynamicArray<int> directFriends = friendGraph.outEdges(userID);
    Map<int, int> friendsOfFriendsCount;  // Map to count mutual friends

    // Iterate over each direct friend of the user
    for (size_t i = 0; i < directFriends.getSize(); ++i) {
        int friendID = directFriends[i];

        // Get friends of each direct friend (friends of friends)
        DynamicArray<int> friendsOfFriend = friendGraph.outEdges(friendID);

        // Iterate over each friend of the direct friend
        for (size_t j = 0; j < friendsOfFriend.getSize(); ++j) {
            int mutualFriendID = friendsOfFriend[j];

            // Skip if the mutual friend is the user itself or already a direct friend
            if (mutualFriendID == userID || directFriends.indexOf(mutualFriendID) != -1) {
                continue;
            }

            // If mutual friend is not already counted, add to the map with a count of 1
            if (!friendsOfFriendsCount.contains(mutualFriendID)) {
                friendsOfFriendsCount.add(mutualFriendID, 1);
            } else {
                // If already counted, increment the count
                int currentCount = friendsOfFriendsCount.get(mutualFriendID);
                friendsOfFriendsCount.add(mutualFriendID, currentCount + 1);
            }
        }
    }

    // Use a priority queue to sort friends based on the number of mutual friends
    PriorityQueue<int> pq;

    // Retrieve all mutual friends and their counts from the map
    DynamicArray<Pair<int, int>> allMutualFriends = friendsOfFriendsCount.getAll();

    // Add each mutual friend to the priority queue with their count as the priority
    for (size_t i = 0; i < allMutualFriends.getSize(); ++i) {
        pq.add(allMutualFriends[i].key, allMutualFriends[i].value);  // key is the friend ID, value is the priority
    }

    // Extract friends from the priority queue, starting with the highest mutual count
    while (!pq.isEmpty()) {
        recommendations.pushBack(pq.pop());
    }

    // Return the list of recommended friends, sorted by mutual connections
    return recommendations;
}


void FriendManager::getRecommendations(int userID) {
    std::cout << "\nFriend recommendations for " << getUserByID(userID).getName() << " (User ID " << userID << "):\n";
    DynamicArray<int> recommendations = recommendFriends(userID);

    if (recommendations.getSize() > 0) {
        std::cout << "Recommended friends: ";
        for (size_t i = 0; i < recommendations.getSize(); ++i) {
            try {
                User recommendedUser = getUserByID(recommendations[i]);
                std::cout << recommendedUser.getName() << " ";
            } catch (const std::exception& e) {
                std::cerr << "Error retrieving user details: " << e.what() << std::endl;
            }
        }
        std::cout << std::endl;
    } else {
        std::cout << "No recommendations available for User " << userID << "." << std::endl;
    }
}

void FriendManager::displayRelationships() const {
    DynamicArray<Pair<int, User>> allUsers = userMap.getAll();
    for (size_t i = 0; i < allUsers.getSize(); ++i) {
        const User& user = allUsers[i].value;
        std::cout << user.getName() << " (User ID " << user.getUserID() << ") has friends: ";

        // Get the friends of the user from the graph
        DynamicArray<int> friends = friendGraph.outEdges(user.getUserID());

        if (friends.getSize() == 0) {
            std::cout << "No friends";
        } else {
            for (size_t j = 0; j < friends.getSize(); ++j) {
                int friendID = friends[j];

                // Ensure the friend ID is valid before attempting to retrieve details
                if (userExists(friendID)) {
                    try {
                        User friendUser = getUserByID(friendID);
                        std::cout << friendUser.getName();
                        if (j < friends.getSize() - 1) {
                            std::cout << ", ";
                        }
                    } catch (const std::exception& e) {
                        std::cerr << "Error retrieving user details: " << e.what() << std::endl;
                    }
                } else {
                    std::cerr << "\nInvalid friend ID " << friendID << " for user " << user.getUserID() << std::endl;
                }
            }
        }
        std::cout << std::endl;
    }
}

bool FriendManager::userExists(int userID) const {
    try {
        userMap.get(userID);
        return true;
    } catch (const std::runtime_error&) {
        return false;
    }
}

void FriendManager::display()const {
    DynamicArray<Pair<int, User>> allusers = userMap.getAll();
    for (size_t i = 0; i < allusers.getSize(); ++i) {
        std::cout << allusers[i] << std::endl;
    }
}

User FriendManager::getUserByID(int userID) const {
    try {
        return userMap.get(userID);
    } catch (const std::runtime_error& e) {
        throw std::runtime_error("User not found");
    }
}
