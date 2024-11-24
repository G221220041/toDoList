#include "Tag.h"
#include <iostream>

Tag::Tag(int id, const std::string& name, const std::string& style)
{
    std::cout << "Tag created: " << name << " with ID " << id << std::endl;
    tagId = id;
    tagName = name;
    tagStyle = style;
}

bool Tag::setName(const std::string& newName) 
{
    std::cout << "Setting name for tag: " << tagId << " to " << newName << std::endl;
    tagName = newName;
    //check logic
    //just to express my logic for once, sure it is stupid because the tagName is not pointer
    if (tagName == newName)
        return true;
    else
        return false;
}

bool Tag::setStyle(const std::string& newStyle) 
{
    std::cout << "Setting style for tag: " << tagId << " to " << newStyle << std::endl;
    tagStyle = newStyle;
    //check logic
    if (tagStyle == newStyle)
        return true;
    else
        return false;
}
