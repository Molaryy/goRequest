//
// Created by mohammed on 05.09.23.
//

#include "jb_src.hpp"
#include <unistd.h>
#include <sys/stat.h>
#include <fcntl.h>

enum {
    INT_TYPE = 0,
    SIZE_T_TYPE = 1,
    CHAR_TYPE = 2,
    BOOL_TYPE = 3,
    DOUBLE_TYPE = 4,
    STR_TYPE = 5,
    VECTOR_STR_TYPE = 6,
    VECTOR_INT_TYPE = 7,
};

typedef struct jsonObjType_s {
    size_t type;
    int jb_int;
    size_t jb_size_t;
    char jb_ch;
    bool jb_bool;
    double jb_double;
    std::string jb_str;
    std::vector<std::string> jb_vect_str;
    std::vector<int> jb_vect_int;
} jsonObjType_t;

typedef struct jb_json_s {
    char *key = nullptr;
    struct jsonObjType_s value;
    struct jb_json_s *next = nullptr;
    struct jb_json_s *prev = nullptr;
} jb_json_t;

jb_json_t *create_jb_json(const jsonObjType_t& type, size_t enum_type)
{
    jb_json_t *node = static_cast<jb_json_t *>(malloc(sizeof(jb_json_t)));

    if (!node) {
        return nullptr;
    }
    node->value.type = enum_type;
    switch (enum_type) {
        case INT_TYPE: node->value.jb_int = type.jb_int; break;
        case SIZE_T_TYPE: node->value.jb_size_t = type.jb_size_t; break;
        case CHAR_TYPE: node->value.jb_ch = type.jb_ch; break;
        case BOOL_TYPE: node->value.jb_bool = type.jb_bool; break;
        case DOUBLE_TYPE: node->value.jb_double = type.jb_double; break;
        case STR_TYPE: node->value.jb_str = type.jb_str; break;
        case VECTOR_STR_TYPE: node->value.jb_vect_str = type.jb_vect_str; break;
        case VECTOR_INT_TYPE: node->value.jb_vect_int = type.jb_vect_int; break;
        default: break;
    }
    node->next = nullptr;
    node->prev = nullptr;
    return node;
}

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
    if (!buffer) {
        return false;
    }
    buffer[info.st_size] = '\0';
    read(fd, buffer, info.st_size);
    data = str_to_vector(buffer, "\n");
    free(buffer);
    close(fd);
    return true;
}

static char *string_to_char_string(std::string str)
{
    char *newStr = (char *)malloc(sizeof(char) * (str.size() + 1));

    if (!newStr){
        return nullptr;
    }
    for (size_t i = 0; str[i]; i++) {
        newStr[i] = str[i];
    }
    newStr[str.size()] = '\0';
    return newStr;
}

static std::string clearKeyInQuotes(std::string key, bool isKey)
{
    bool isInString = false;
    std::string newStr;


    for (size_t i = 0; key[i]; i++) {
        if (key[i] == '\"' && isInString) {
            break;
        }
        if (key[i] == '\"') {
            isInString = true;
        }
        if (isInString && key[i] != '\"') {
            newStr.push_back(key[i]);
        }
    }
    if (isKey) {
        newStr.push_back(':');
    }
    return newStr;
}

extern void JsonObj::parseDataToJsonObj()
{
    char *line = nullptr;
    std::vector<std::string> parents;
    size_t j = 0;
    bool addParent = false;

    for (const auto &inData : data) {
        if (!(line = string_to_char_string(inData))) {
            return;
        }
        std::vector<std::string> lineVector = str_to_vector(line, " \t\n,{}[]");
        std::vector<std::string> parentValidator = str_to_vector(line, " \t\n,");

        free(line);

        if (check_str_last_index(parentValidator[0], ':') && parentValidator[1][0] == '{') {
            parents.push_back(clearKeyInQuotes(parentValidator[0], false));
            addParent = true;
        } else if (addParent && parentValidator[0][0] == '}'){
            addParent = false;
        }

        for (size_t i = 0; i < lineVector.size(); i++) {
            if (check_str_last_index(lineVector[i], ':')) {
                lineVector[i] = clearKeyInQuotes(lineVector[i], false);
                if (addParent && i + 1 < lineVector.size() && !check_str_last_index(lineVector[i + 1], ':')){
                    std::cout << parents[0] << "/";
                }
                std::cout << lineVector[i];
                std::cout << " => ";
                for  (; i + 1 < lineVector.size() && !check_str_last_index(lineVector[i + 1], ':'); i++) {
                    std::string value;
                    if (check_str_last_index(lineVector[i + 1], ',')) {
                        lineVector[i + 1].pop_back();
                    }
                    std::cout << lineVector[i + 1] << " ";
                }
                std::cout << "\n\n";
            }
        }
    }
}
