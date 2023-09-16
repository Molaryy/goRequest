//
// Created by mohammed on 03.09.23.
//

#ifndef JB_INT_HPP
    #define JB_INT_HPP
#include <iostream>
using namespace std;

/**
 * @brief get the number in a string.
 * @param const char *str
 * @return the integer corresponding to the string given in params
 */
extern int getNumber(const char *str);

/**
 * @brief get the size of a string
 * @param std::string
 * @return integer corresponding to the size of the string
 * */
extern size_t str_len(std::string);

#endif /* JB_INT_HPP */
