//
// Created by mohammed on 17.12.23.
//

#include <unistd.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdlib.h>

extern char *get_file_content(const char *filepath)
{
    int fd = open(filepath, O_RDONLY);
    char *buffer;
    struct stat info = {};

    if (fd < 0 || stat(filepath, &info) < 0) {
        return nullptr;
    }
    buffer = (char *)malloc(sizeof(char) * (info.st_size + 1));
    if (!buffer) {
        return nullptr;
    }
    buffer[info.st_size] = '\0';
    if (read(fd, buffer, info.st_size) == -1) {
        close(fd);
        return nullptr;
    }
    close(fd);
    return (buffer);
}
