#ifndef FRIENDDHANDLERAPP_H_INCLUDED
#define FRIENDDHANDLERAPP_H_INCLUDED

#include "FriendManager.h"

class FriendsHandlerApp {
public:
    FriendsHandlerApp();

    void displayMenu() const;
    void handleAddUser();
    void handleAddFriendship();
    void handleDisplayUsers() const;
    void handleDisplayRelationships();
    void handleRecommendFriends() ;

    void handleExit() const;
    void run();

private:
    FriendManager friendRel;
};

#endif // FRIENDDHANDLERAPP_H_INCLUDED
