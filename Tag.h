#ifndef TAG_H
#define TAG_H

#include <string>

class Tag 
{
public:
    int tagId;
    std::string tagName;
    std::string tagStyle;

    Tag(int id, const std::string& name, const std::string& style);
    bool setName(const std::string& newName);
    bool setStyle(const std::string& newStyle);
};

#endif
