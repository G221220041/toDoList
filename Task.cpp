#include "Task.h"
#include <iostream>

Task::Task(int id, const std::string& t, const std::string& d, std::tm date) {
    std::cout << "Task Created: " << t << " with ID " << id << std::endl;
    taskId = id;
    title = t;
    description = d;
    dueDate = date;
    status = "active";
    isPrivate = false;
    hasReminder = false;
}

bool Task::setPrivate() {
    std::cout << "Task " << taskId <<
        " marked as private" << std::endl;
    isPrivate = true;
    return true;
}

bool Task::resetPrivate() {
    std::cout << "Task " << taskId <<
        " marked as public" << std::endl;
    isPrivate = false;
    return true;
}

Tag* Task::createTag(const std::string& tagName, const std::string& tagStyle) {
    std::cout << "Creating tag for task " << taskId <<
        " with name: " << tagName << std::endl;
    Tag* newTag = new Tag(tags.size() + 1, tagName, tagStyle);
    if (newTag == nullptr) {
        std::cout << "Creating tag failed" << std::endl;
        return nullptr;
    } else {
        tags.push_back(newTag);
        return newTag;
    }
}

bool Task::deleteTag(Tag* tag) {
    std::cout << "Deleting tag " << tag->getName() <<
        " from task " << taskId << std::endl;
    auto it = std::find(tags.begin(), tags.end(), tag);
    if (it != tags.end()) {
        tags.erase(it);
        delete tag;
        std::cout << "Delete tag success" << std::endl;
        return true;
    }
    std::cout << "Can not find this tag" << std::endl;
    return false;
}

bool Task::attachFile(TaskFile* file) {
    std::cout << "Attaching file " << file->getPath() <<
        " to task " << taskId << std::endl;
    files.push_back(file);
    return true;
}

bool Task::removeFile(TaskFile* file) {
    std::cout << "Removing file " << file->getPath() <<
        " from task " << taskId << std::endl;
    auto it = std::find(files.begin(), files.end(), file);
    if (it != files.end()) {
        files.erase(it);
        delete file;
        std::cout << "Remove file success" << std::endl;
        return true;
    }
    std::cout << "Can not find this file" << std::endl;
    return false;
}

bool Task::assignTag(Tag* tag) {
    std::cout << "Assigning tag " << tag->getName() <<
        " to task " << taskId << std::endl;
    tags.push_back(tag);
    return true;
}

bool Task::removeTag(Tag* tag) {
    std::cout << "Removing tag " << tag->getName() <<
        " from task " << taskId << std::endl;
    auto it = std::find(tags.begin(), tags.end(), tag);
    if (it != tags.end()) {
        tags.erase(it);
        std::cout << "Remove tag success" << std::endl;
        return true;
    }
    std::cout << "Can not find this tag" << std::endl;
    return false;
}

Reminder* Task::createReminder(std::tm time) {
    std::cout << "Create reminder for task " << taskId << std::endl;
    hasReminder = true;
    Reminder* newReminder = new Reminder(reminders.size() + 1, taskId, time);
    if (newReminder == nullptr) {
        std::cout << "Creating reminder failed" << std::endl;
        return nullptr;
    } else {
        reminders.push_back(newReminder);
        return newReminder;
    }
}

bool Task::deleteReminder(Reminder* reminder) {
    std::cout << "delete reminder for task " << taskId << std::endl;
    hasReminder = false;
    auto it = std::find(reminders.begin(), reminders.end(), reminder);
    if (it != reminders.end()) {
        reminders.erase(it);
        delete reminder;
        std::cout << "Delete reminder success" << std::endl;
        return true;
    }
    std::cout << "Can not find this reminder" << std::endl;
    return false;
}

std::string Task::getTitle() {
    std::cout << "Get task title" << std::endl;
    return title;
}

bool Task::setTitle(std::string t) {
    std::cout << "Set task title to " << t << std::endl;
    title = t;
    return true;
}

std::string Task::getDescription() {
    std::cout << "Get task description" << std::endl;
    return description;
}

bool Task::setDescription(std::string d) {
    std::cout << "Set task description to " << d << std::endl;
    description = d;
    return true;
}

int Task::getId() {
    std::cout << "Get task id" << std::endl;
    return taskId;
}

std::tm Task::getdueDate() {
    std::cout << "Get task due date" << std::endl;
    return dueDate;
}

bool Task::setdueDate(std::tm date) {
    std::cout << "Set task due date to " << std::asctime(&date) << std::endl;
    dueDate = date;
    return true;
}

std::string Task::getstatus() {
    std::cout << "Get task status" << std::endl;
    return status;
}

bool Task::setstatus(std::string s) {
    std::cout << "Set task status to " << s << std::endl;
    status = s;
    return true;
}

void Task::displayTaskInfo() {
    std::cout << "Task ID: " << taskId << ", Title: " << title <<
        ", Description: " << description
        << ", Due Date: " << asctime(&dueDate) << ", Status: " << status <<
        ", Private: " << isPrivate
        << std::endl;
}
