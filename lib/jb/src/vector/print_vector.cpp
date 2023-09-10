//
// Created by mohammed on 10.09.23.
//

#include "jb_src.hpp"

extern void print_vector(const std::vector<void *> &vector)
{
    if (vector.empty()){
        std::cerr << "The vector is empty\n";
    }
    for (const auto &inVector : vector) {
        std::cout << inVector << std::endl;
    }
}
