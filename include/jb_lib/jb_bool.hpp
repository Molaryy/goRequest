//
// Created by mohammed on 03.09.23.
//

#ifndef JB_BOOL_HPP
    #define JB_BOOL_HPP
#include <iostream>
using namespace std;

/**
* @brief checks if a char is a num or not
* @return true if the char given is a number else returns false
*/
extern bool charIsNum(char c);

/**
* @brief checks if a char matches with the last char of a string
* @return true if the char given is equal to the last char of the string else return false
*/
extern bool check_str_last_index(std::string str, char charEnd);

#endif /* JB_BOOL_HPP */
