#include <iostream>
#include <ctime>
#include "User.h"

int main() {
    // create user and log in
    User user(1, "xs", "123", "xs@example.com");
    std::string username;
    std::string password;
    while (1) {
        std::cout << "please give me your username and password:" << std::endl;
        std::cin >> username >> password;
        if (user.login(username, password)) {
            std::cout << "User logged in successfully!" << std::endl;
            break;
        } else {
            std::cout << "Login failed! Please try again" << std::endl;
        }
    }

    // user choose to create task
    std::cout << "\nCreating task...\n";
    std::tm dueDate = {};
    dueDate.tm_year = 2024 - 1900;  // year 2024
    dueDate.tm_mon = 10 - 1;  // October
    dueDate.tm_mday = 15;  // 15th

    Task* newTask = user.createTask(1, "Study for exam",
        "Prepare for upcoming exam", dueDate);
    newTask->displayTaskInfo();

    // user choose to set the task to private
    char privacyChoice;
    std::cout << "\nDo you want to mark the task as private? (y/n): ";
    std::cin >> privacyChoice;
    if (privacyChoice == 'y' || privacyChoice == 'Y') {
        newTask->setPrivate();
    } else {
        std::cout << "Task remains public." << std::endl;
    }

    // user choose to set tags for task
    Tag* newTag = newTask->createTag("Important", "Red");

    // user choose to attach file for task
    TaskFile* file = new TaskFile(1, "/files/study_guide.pdf",
        newTask->getId());
    newTask->attachFile(file);

    // user choose to set reminder
    newTask->createReminder(dueDate);

    // user choose to update the task
    char updateChoice;
    std::cout << "\nDo you want to update the task? (y/n): ";
    std::cin >> updateChoice;
    if (updateChoice == 'y' || updateChoice == 'Y') {
        std::cout << "Editing task...\n";
        newTask->setTitle("Revised Study Plan");
        newTask->setDescription("Prepare for final exam.");
        newTask->displayTaskInfo();
    }

    // user choose to delete the task
    char deleteChoice;
    std::cout << "\nDo you want to delete the task? (y/n): ";
    std::cin >> deleteChoice;
    if (deleteChoice == 'y' || deleteChoice == 'Y') {
        std::cout << "Deleting task...\n";
        user.deleteTask(newTask);
    }

    // user choose to log out
    if (user.logout())
        std::cout << "\nUser logged out successfully!" << std::endl;

    return 0;
}
