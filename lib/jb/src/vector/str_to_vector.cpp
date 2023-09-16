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
        if (!str[i + 1] && str[i] && !is_separator(str[i], separators)) {
            newStr.push_back(str[i]);
        }
        for (; str[i + 1] && !is_separator(str[i], separators); i++) {
            newStr += str[i];
            if (!str[i + 2]){
                newStr += str[i + 1];
            }
        }
        if (!newStr.empty()) {
            strArray.emplace_back(newStr);
        }
    }
    return strArray;
}
