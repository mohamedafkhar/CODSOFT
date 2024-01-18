#include <iostream>
#include <vector>
#include <iomanip>

struct Task {
    std::string description;
    bool completed;
};

// Function to display the to-do list
void displayTasks(const std::vector<Task>& tasks) {
    if (tasks.empty()) {
        std::cout << "No tasks in the to-do list." << std::endl;
    } else {
        std::cout << std::left << std::setw(4) << "ID" << std::setw(30) << "Description" << "Status" << std::endl;
        std::cout << std::setfill('-') << std::setw(45) << "" << std::setfill(' ') << std::endl;

        for (size_t i = 0; i < tasks.size(); ++i) {
            std::cout << std::left << std::setw(4) << i + 1 << std::setw(30) << tasks[i].description;
            std::cout << (tasks[i].completed ? "Completed" : "Pending") << std::endl;
        }
    }
}

// Function to add a task to the to-do list
void addTask(std::vector<Task>& tasks, const std::string& description) {
    Task newTask{ description, false };
    tasks.push_back(newTask);
    std::cout << "Task added successfully." << std::endl;
}

// Function to mark a task as completed
void markTaskCompleted(std::vector<Task>& tasks, size_t taskId) {
    if (taskId >= 1 && taskId <= tasks.size()) {
        tasks[taskId - 1].completed = true;
        std::cout << "Task marked as completed." << std::endl;
    } else {
        std::cout << "Invalid task ID. Please enter a valid ID." << std::endl;
    }
}

// Function to remove a task from the to-do list
void removeTask(std::vector<Task>& tasks, size_t taskId) {
    if (taskId >= 1 && taskId <= tasks.size()) {
        tasks.erase(tasks.begin() + taskId - 1);
        std::cout << "Task removed successfully." << std::endl;
    } else {
        std::cout << "Invalid task ID. Please enter a valid ID." << std::endl;
    }
}

int main() {
    std::vector<Task> tasks;

    while (true) {
        std::cout << "\n===== TO-DO LIST MANAGER =====" << std::endl;
        std::cout << "1. Add Task\n2. View Tasks\n3. Mark Task as Completed\n4. Remove Task\n5. Exit" << std::endl;

        int choice;
        std::cout << "Enter your choice (1-5): ";
        std::cin >> choice;

        switch (choice) {
            case 1: {
                std::string description;
                std::cout << "Enter task description: ";
                std::cin.ignore();
                std::getline(std::cin, description);
                addTask(tasks, description);
                break;
            }
            case 2:
                displayTasks(tasks);
                break;
            case 3: {
                size_t taskId;
                std::cout << "Enter the ID of the task to mark as completed: ";
                std::cin >> taskId;
                markTaskCompleted(tasks, taskId);
                break;
            }
            case 4: {
                size_t taskId;
                std::cout << "Enter the ID of the task to remove: ";
                std::cin >> taskId;
                removeTask(tasks, taskId);
                break;
            }
            case 5:
                std::cout << "Exiting the to-do list manager. Goodbye!" << std::endl;
                return 0;
            default:
                std::cout << "Invalid choice. Please enter a valid option (1-5)." << std::endl;
        }
    }

    return 0;
}
