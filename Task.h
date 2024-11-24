#ifndef TASK_H
#define TASK_H

#include <iostream>
#include <vector>
#include <string>
#include <ctime>
#include "Tag.h"
#include "TaskFile.h"
#include "Reminder.h"

class Task 
{
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
    void displayTaskInfo();
};

#endif
