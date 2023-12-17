//
// Created by mohammed on 17.12.23.
//

#include "jb_src.hpp"


extern char *env_value(const char *key)
{
    const char *buffer = get_file_content(".env");
    std::vector<std::string> parsed_buffer = str_to_vector(buffer, "\n");

    for (auto line : parsed_buffer) {
        std::vector<std::string> parsed_line = str_to_vector(buffer, "=");
        if (vector_len(parsed_line) == 2 && parsed_line[0] == key) {
            std::cout << parsed_line[1];
            return std_str_to_char_str(parsed_line[1]);
        }
    }

    std::cerr << "Couldn't get key: " << key << " from .env" << std::endl;
    return nullptr;
}
