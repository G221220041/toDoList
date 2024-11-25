#ifndef REMINDER_H_
#define REMINDER_H_

#include <string>

class Reminder {
 private:
    int reminderId;
    int taskId;
    std::tm reminderTime;

 public:
    Reminder(int id, int tid, std::tm time);
    bool setReminder(std::tm time);
};

#endif  // REMINDER_H_
