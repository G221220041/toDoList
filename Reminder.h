#ifndef REMINDER_H_
#define REMINDER_H_

#include <string>
#include <ctime>

class Reminder {
 private:
    int reminderId;
    int taskId;
    std::tm reminderTime;

 public:
    Reminder(int id, int tid, std::tm time);
    bool setReminder(std::tm time);
    std::tm getReminder();
};

#endif  // REMINDER_H_

