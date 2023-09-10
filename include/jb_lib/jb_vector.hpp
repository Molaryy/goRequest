//
// Created by mohammed on 10.09.23.
//

#ifndef GOREQUEST_JB_VECTOR_HPP
#define GOREQUEST_JB_VECTOR_HPP

/**
 * @brief creates a vector with a string parsed with the separators of your choice
 * @param const char *str: the string you want to parse
 * @param const char *separators: the char separators
 * @return std::vector<std::string>
 */
extern std::vector<std::string> str_to_vector(const char *str, const char *separators);

/**
 * @brief prints a std::vector container any value
 * @param const std::vector<void *> &vector
 */
extern void print_vector(const std::vector<void *> &vector);
#endif //GOREQUEST_JB_VECTOR_HPP
