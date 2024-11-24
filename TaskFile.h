#ifndef TASKFILE_H
#define TASKFILE_H

#include <string>

class TaskFile 
{
public:
    int fileId;
    std::string filePath;
    int taskId;

    TaskFile(int id, const std::string& path, int task);
    bool checkFile();
};

#endif
