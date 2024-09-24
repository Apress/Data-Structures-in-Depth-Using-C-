#ifndef TASKMANAGER_H_INCLUDED
#define TASKMANAGER_H_INCLUDED

#include <string>
#include "PriorityQueue.h"
#include "Map.h"

class Task {
public:
    int Id;
    std::string description;
    int priority;

    // Default constructor
    Task()
        : Id(0), description(""), priority(0) {}

    // Parameterized constructor
    Task(int id)
        : Id(id), description(""), priority(0) {}

    // Parameterized constructor
    Task(int id, std::string desc, int prio)
        : Id(id), description(desc), priority(prio) {}

    // Overload == operator for Task
    bool operator==(const Task& other) const {
        return Id == other.Id &&
               description == other.description &&
               priority == other.priority
    ;
    }

     // Overload << operator for Task
    friend std::ostream& operator<<(std::ostream& os, const Task& task) {
        os << "Task ID: " << task.Id
           << ", Description: " << task.description
           << ", Priority: " << task.priority;
        return os;
    }
};


class TaskManager {
public:
    // Default constructor
    TaskManager();

    // Adds a new task to the system
    void addTask(const Task& task);

    // Removes a completed task from the system
    void removeTask(int taskID);

    // Fetches the highest-priority task
    Task getNextTask() const;

    // Displays all current tasks
    void viewTasks() const;

    // Check if there are tasks
    bool hasTasks() const;

    // Clears all tasks from the system
    void clearAllTasks();

    // Returns the count of tasks
    size_t getTaskCount() const;

    // Completes and returns the highest priority task
    Task completeHighestPriorityTask();

private:
    //Map<int, Task> tasksMap;
    PriorityQueue<Task> taskQueue;
};

#endif // TASKMANAGER_H_INCLUDED
