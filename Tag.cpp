#include "Tag.h"
#include <iostream>

Tag::Tag(int id, const std::string& name, const std::string& style)
    : tagId(id), tagName(name), tagStyle(style) {
    std::cout << "Tag created: " << tagName << " with ID " << tagId << std::endl;
}

bool Tag::setName(const std::string& newName) {
    std::cout << "Setting name for tag: " << tagId << " to " << newName << std::endl;
    tagName = newName;
    return true;
}

bool Tag::setStyle(const std::string& newStyle) {
    std::cout << "Setting style for tag: " << tagId << " to " << newStyle << std::endl;
    tagStyle = newStyle;
    return true;
}
