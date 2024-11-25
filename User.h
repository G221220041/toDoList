#ifndef USER_H_
#define USER_H_

#include <string>
#include "Task.h"

class User {
 private:
    int userId;
    std::string username;
    std::string password;
    std::string email;
    int status;

 public:
    User(int id, const std::string& uname, const std::string& pwd,
        const std::string& mail);
    bool login(const std::string& uname, const std::string& pwd);
    bool logout();
    Task* createTask(int taskId, const std::string& title,
        const std::string& description, std::tm dueDate);
    bool deleteTask(Task* task);
};

#endif  // USER_H_
