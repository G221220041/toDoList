#include "TaskFile.h"
#include <iostream>

TaskFile::TaskFile(int id, const std::string& path, int task)
    : fileId(id), filePath(path), taskId(task) {
    std::cout << "TaskFile created: " << filePath << " with ID " << fileId << std::endl;
}

bool TaskFile::checkFile() {
    std::cout << "Checking file: " << filePath << " associated with task ID: " << taskId << std::endl;
    // Simulate file check logic here
    /*
    * if(filepath exists and taskid is associted with file)
    *   return true;
    * else
    *   return false;
    */
    return true;
}
