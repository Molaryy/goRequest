//
// Created by mohammed on 05.09.23.
//
#include "jb_src.hpp"
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>


JsonObj::JsonObj(char *filePath) {
    this->filePath = filePath;
};

bool JsonObj::getFile()
{
    int fd = open(filePath, O_RDONLY);

    if (fd < 0) {
        return false;
    }
    this->data.emplace_back(filePath);
    std::cout << this->data[0] << "\n";
    return true;
}
