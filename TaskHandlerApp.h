#ifndef TASKHANDLERAPP_H_INCLUDED
#define TASKHANDLERAPP_H_INCLUDED

#include "TaskManager.h"
#include <iostream>

class TaskHandlerApp {
public:
    TaskHandlerApp();
    void run();

private:
    TaskManager taskManager;

    void displayMenu() const;
    void handleAddTask();
    void handleRemoveTask();
    void handleDisplayTasks() const;
    void handleCompleteHighestTask();
    void handleGetNextTask() const;
    void handleClearAllTasks();
    void handleExit() const;

    void printTaskCount() const;
};

#endif // TASKHANDLERAPP_H_INCLUDED
