#include "User.h"
#include <iostream>

User::User(int id, const std::string& uname, const std::string& pwd,
    const std::string& mail) {
    userId = id;
    username = uname;
    password = pwd;
    email = mail;
    status = 0;
}

bool User::login(const std::string& uname, const std::string& pwd) {
    if (username == uname && password == pwd) {
        std::cout << "User " << username << " logged in" << std::endl;
        status = 1;
        return true;
    } else {
        std::cout << "Wrong password" << std::endl;
        return false;
    }
}

bool User::logout() {
    std::cout << "User " << username << " logged out" << std::endl;
    status = 0;
    return true;
}

Task* User::createTask(int taskId, const std::string& title,
    const std::string& description, std::tm dueDate) {
    Task* newTask = new Task(taskId, title, description, dueDate);
    if (newTask == nullptr) {
        std::cout << "Create new task failed" << std::endl;
        return nullptr;
    } else {
        std::cout << "User " << username << " creating task "
            << title << std::endl;
        return newTask;
    }
}

bool User::deleteTask(Task* task) {
    std::cout << "User " << username << " deleting task " <<
        task->getTitle() << std::endl;
    delete task;
    return true;
}
