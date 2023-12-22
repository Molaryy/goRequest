//
// Created by mohammed on 22.12.23.
//

#include <iostream>
#include <vector>

extern std::string vector_to_string(std::vector<std::string> vector, const char * separators)
{
    std::string str = "";

    for (size_t i = 0; i < vector.size(); i++) {
        str = str.append(vector[i]);
        if (i + 1 < vector.size()) {
            str = str.append(separators);
        }
    }

    return str;
}
