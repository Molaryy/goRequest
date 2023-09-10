//
// Created by mohammed on 09.09.23.
//

#include "jb_src.hpp"

static bool is_separator(char c, const char *separators)
{
    for (; *separators; *separators++) {
        if (*separators == c){
            return true;
        }
    }
    return false;
}

extern std::vector<std::string> str_to_vector(const char *str, const char *separators)
{
    std::vector<std::string> strArray;
    std::string newStr;

    for (size_t i = 0; str[i]; i++) {
        newStr.clear();
        for (; str[i] && !is_separator(str[i], separators); i++) {
            newStr += str[i];
        }
        if (!newStr.empty()){
            strArray.push_back(newStr);
        }
    }
    return strArray;
}
