#include"Reminder.h"
#include <iostream>

Reminder::Reminder(int id, int tid, std::tm time) {
    std::cout << "Reminder Created with ID " << id << std::endl;
    reminderId = id;
    taskId = tid;
    reminderTime = time;
}

bool Reminder::setReminder(std::tm time) {
    std::cout << "Setting time for reminder: " << reminderId <<
        " to " << std::asctime(&time) << std::endl;
    reminderTime = time;
    return true;
}

std::tm Reminder::getReminder() {
    std::cout << "Get reminder time" << std::endl;
    return reminderTime;
}
