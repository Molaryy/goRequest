//
// Created by mohammed on 17.12.23.
//

#include <iostream>

/**
 * @brief std::string to char *
 * @param std::string str
 * @returns char * copy from str
 *
*/
extern char *std_str_to_char_str(std::string str);

/**
 * @brief Converts a vector to a std::string
 * @param std::vector<std::string> vector
 * @param const char * separators: the separators what will separate the strings
 * @returns std::string
 *
*/
extern std::string vector_to_string(std::vector<std::string> vector, const char * separators);