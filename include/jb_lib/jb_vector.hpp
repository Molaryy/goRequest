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
 * @param template<T> type that is printable
 * @param debugMode false to print normal vector or true to print vector with debug strings
 */
template <typename T>
extern void print_vector(const std::vector<T> &vector, bool debugMode)
{
    if (vector.empty()){
        std::cerr << "The vector is empty\n";
    }
    for (const auto &inVector : vector) {
        if (!debugMode){
            std::cout << inVector << std::endl;
        } else {
            std::cout << "[ " << inVector << " ]" << "\n\n";
        }
    }
}

#endif //GOREQUEST_JB_VECTOR_HPP
