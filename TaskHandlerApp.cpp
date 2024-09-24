#include "TaskHandlerApp.h"
#include "TaskManager.h"

TaskHandlerApp::TaskHandlerApp() : taskManager() {}

void TaskHandlerApp::displayMenu() const {
    std::cout << "\n=== Task Manager Menu ===\n";
    std::cout << "1. Add Task\n";
    std::cout << "2. Remove Task\n";
    std::cout << "3. Display Tasks\n";
    std::cout << "4. Complete Highest Priority Task\n";
    std::cout << "5. Get Next Highest Priority Task\n";
    std::cout << "6. Clear All Tasks\n";
    std::cout << "7. Exit\n";
    std::cout << "Enter your choice: ";
}

void TaskHandlerApp::handleAddTask() {
    int id, priority;
    std::string description;
    std::cout << "Enter Task ID: ";
    std::cin >> id;
    std::cin.ignore(); // To ignore newline character left in buffer
    std::cout << "Enter Task Description: ";
    std::getline(std::cin, description);
    std::cout << "Enter Task Priority: ";
    std::cin >> priority;
    taskManager.addTask(Task(id, description, priority));
}

void TaskHandlerApp::handleRemoveTask() {
    int id;
    std::cout << "Enter Task ID to remove: ";
    std::cin >> id;
    try {
        taskManager.removeTask(id);
        std::cout << "Task removed successfully." << std::endl;
    } catch (const std::runtime_error& e) {
        std::cerr << "Error: " << e.what() << std::endl;
    }
}

void TaskHandlerApp::handleDisplayTasks() const {
    std::cout << "\n=== Current Tasks ===\n";
    printTaskCount();
    taskManager.viewTasks();
}

void TaskHandlerApp::handleCompleteHighestTask() {
    try {
        Task highestTask = taskManager.completeHighestPriorityTask();
        std::cout << "Completed task:\n" << highestTask << std::endl;
    } catch (const std::runtime_error& e) {
        std::cerr << "Error: " << e.what() << std::endl;
    }
}

void TaskHandlerApp::handleGetNextTask() const {
    try {
        Task nextTask = taskManager.getNextTask();
        std::cout << "Next highest-priority task:\n" << nextTask << std::endl;
    } catch (const std::runtime_error& e) {
        std::cerr << "Error: " << e.what() << std::endl;
    }
}

void TaskHandlerApp::handleClearAllTasks() {
    taskManager.clearAllTasks();
    std::cout << "All tasks have been cleared." << std::endl;
}

void TaskHandlerApp::handleExit() const {
    std::cout << "Exiting Task Manager.\n";
}

void TaskHandlerApp::printTaskCount() const {
    std::cout << "Total number of tasks: " << taskManager.getTaskCount() << std::endl;
}

void TaskHandlerApp::run() {
    int choice;
    do {
        displayMenu();
        std::cin >> choice;

        switch (choice) {
            case 1:
                handleAddTask();
                break;
            case 2:
                handleRemoveTask();
                break;
            case 3:
                handleDisplayTasks();
                break;
            case 4:
                handleCompleteHighestTask();
                break;
            case 5:
                handleGetNextTask();
                break;
            case 6:
                handleClearAllTasks();
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
