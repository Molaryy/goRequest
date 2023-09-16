//
// Created by mohammed on 15.09.23.
//

#include <iostream>
#include "jb_lib/jb_int.hpp"

extern bool check_str_last_index(std::string str, char charEnd)
{
    return (str[str_len(str) - 1] == charEnd) ? true : false;
}
