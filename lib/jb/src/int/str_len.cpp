//
// Created by mohammed on 15.09.23.
//

#include <iostream>

extern size_t str_len(std::string str)
{
    size_t count = 0;

    for (; str[count]; count++);
    return count;
}
