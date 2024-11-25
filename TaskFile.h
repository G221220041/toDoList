#ifndef TASKFILE_H_
#define TASKFILE_H_

#include <string>

class TaskFile {
 private:
    int fileId;
    std::string filePath;
    int taskId;

 public:
    TaskFile(int id, const std::string& path, int task);
    bool checkFile();
};

#endif  // TASKFILE_H_
