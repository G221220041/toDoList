#ifndef TASK_H_
#define TASK_H_

#include <iostream>
#include <vector>
#include <string>
#include <ctime>
#include "Tag.h"
#include "TaskFile.h"
#include "Reminder.h"

class Task {
 private:
    int taskId;
    std::string title;
    std::string description;
    std::tm dueDate;
    std::string status;
    bool isPrivate;
    std::vector<Tag*> tags;
    std::vector<TaskFile*> files;
    std::vector<Reminder*> reminders;
    bool hasReminder;

 public:
    Task(int id, const std::string& t, const std::string& d, std::tm date);
    bool setPrivate();
    bool resetPrivate();
    Tag* createTag(const std::string& tagName, const std::string& tagStyle);
    bool deleteTag(Tag* tag);
    bool attachFile(TaskFile* file);
    bool removeFile(TaskFile* file);
    bool assignTag(Tag* tag);
    bool removeTag(Tag* tag);
    Reminder* createReminder(std::tm time);
    bool deleteReminder(Reminder* reminder);
    std::string getTitle();
    bool setTitle(std::string t);
    int getId();
    std::string getDescription();
    bool setDescription(std::string d);
    std::tm getdueDate();
    bool setdueDate(std::tm date);
    std::string getstatus();
    bool setstatus(std::string s);
    void displayTaskInfo();
};

#endif  // TASK_H_
