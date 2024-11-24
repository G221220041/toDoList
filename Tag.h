#ifndef TAG_H_
#define TAG_H_

#include <string>

class Tag{
 private:
    int tagId;
    std::string tagName;
    std::string tagStyle;

 public:
    Tag(int id, const std::string& name, const std::string& style);
    bool setName(const std::string& newName);
    bool setStyle(const std::string& newStyle);
};

#endif  // TAG_H_
