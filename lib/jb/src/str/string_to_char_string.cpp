//
// Created by mohammed on 17.12.23.
//

#include "jb_src.hpp"

extern char *std_str_to_char_str(std::string str)
{
    char *newStr = (char *)malloc(sizeof(char) * (str.size() + 1));

    if (!newStr){
        return nullptr;
    }
    for (size_t i = 0; str[i]; i++) {
        newStr[i] = str[i];
    }
    newStr[str.size()] = '\0';
    return newStr;
}
