#include "TaskManager.h"

// Default constructor
TaskManager::TaskManager()
    : taskQueue()   // Default initialization of PriorityQueue
{}


void TaskManager::addTask(const Task& task) {
    taskQueue.add(task, task.priority);
}

void TaskManager::removeTask(int taskID) {
    PriorityQueue<Task> newQueue;

    // Sequentially search for the task in the queue and rebuild the queue without the task.
    while (!taskQueue.isEmpty()) {
        Task currentTask = taskQueue.pop();  // Remove the root element

        if (currentTask.Id != taskID) {
            // If it's not the task to remove
            // add it back to the new queue
            newQueue.add(currentTask, currentTask.priority);
        }
    }

    // Replace the old queue with the new one
    taskQueue = std::move(newQueue);
}

Task TaskManager::getNextTask() const {
    if (taskQueue.isEmpty()) {
        throw std::runtime_error("No tasks available");
    }
    return taskQueue.peek();
}

void TaskManager::viewTasks() const {
    if (!taskQueue.isEmpty()) {
        taskQueue.print();
    } else {
        std::cout << "No tasks available." << std::endl;
    }
}

bool TaskManager::hasTasks() const {
    return !taskQueue.isEmpty();
}

size_t TaskManager::getTaskCount() const {
    return taskQueue.getSize();
}

Task TaskManager::completeHighestPriorityTask() {
    if (taskQueue.isEmpty()) {
        throw std::runtime_error("No tasks available to complete.");
    }

    Task highestTask = taskQueue.pop();
    return highestTask;
}

// Clears all tasks
void TaskManager::clearAllTasks() {
    taskQueue.clear();
}

/*
void TaskManager::rebuildQueue() {
    PriorityQueue<Task> newQueue;

    // Retrieve all tasks from the map
    DynamicArray<Pair<int, Task>> allTasks = tasksMap.getAll();

    // Iterate through all tasks
    // add them to the new priority queue
    for (size_t i = 0; i < allTasks.getSize(); ++i) {
        const Task& task = allTasks[i].value;
        newQueue.add(task, task.priority);
    }

    // Replace the old priority queue with the new one
    taskQueue = std::move(newQueue);
}*/
