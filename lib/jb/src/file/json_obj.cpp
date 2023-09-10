//
// Created by mohammed on 05.09.23.
//
#include "jb_src.hpp"
#include <sys/types.h>
#include <unistd.h>
#include <sys/stat.h>
#include <fcntl.h>

typedef struct jsonType_s {
    char *key;
    std::vector<std::string> children;
    jsonType_s *next;
} jsonType_t;

JsonObj::JsonObj(const char *filePath) {
    this->filePath = filePath;
};

bool JsonObj::getFile()
{
    int fd = open(filePath, O_RDONLY);
    char *buffer;
    struct stat info = {};

    if (fd < 0 || stat(filePath, &info) < 0) {
        return false;
    }
    buffer = (char *)malloc(sizeof(char) * (info.st_size + 1));
    buffer[info.st_size] = '\0';
    read(fd, buffer, info.st_size);
    data = str_to_vector(buffer, "\n");
    free(buffer);
    return true;
}

