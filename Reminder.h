#ifndef REMINDER_H
#define REMINDER_H

#include <string>

class Reminder
{
public:
    int reminderId;
    int taskId;
    std::tm reminderTime;

    Reminder(int id, int tid, std::tm time);
    bool setReminder(std::tm time);
};

#endif
