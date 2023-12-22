//
// Created by mohammed on 05.09.23.
//

#include "jb_src.hpp"
#include "jb_lib/jb_file.hpp"

jb_json_t *create_jb_json(jsonObjType_t value, size_t enum_type)
{
    auto *node = new jb_json_t;

    if (!node) {
        return nullptr;
    }
    node->value.type = enum_type;
    node->value.jb_int = value.jb_int;
    node->value.jb_size_t = value.jb_size_t;
    node->value.jb_ch = value.jb_ch;
    node->value.jb_bool = value.jb_bool;
    node->value.jb_double = value.jb_double;
    node->value.jb_str = value.jb_str;
    node->value.jb_vect_str = value.jb_vect_str;
    node->value.jb_vect_int = value.jb_vect_int;
    node->next = nullptr;
    node->prev = nullptr;
    return node;
}

void add_json_element(jb_json_t **node, jsonObjType_t value)
{
    auto *new_node = static_cast<jb_json_t *>(malloc(sizeof(jb_json_t)));

    if (!new_node) {
        std::cerr << "malloc failed add_json_element\n";
        return;
    }
    new_node->prev = *node;
    new_node->value = std::move(value);
    new_node->next = nullptr;
    for (; (*node)->next; *node = (*node)->next);
    (*node)->next = new_node;
    for (; (*node)->prev; *node = (*node)->prev);
}

JsonObj::JsonObj(const char *filePath) {
    this->filePath = filePath;
};

bool JsonObj::getFile()
{
    char *buffer = get_file_content(filePath);
    data = str_to_vector(buffer, "\n");
    free(buffer);
    return true;
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

void print_link_json(jb_json_t *node)
{
    for (; node; node = node->next) {
        switch (node->value.type) {
            case JB_INT_TYPE: std::cout << node->value.jb_int << "\n"; break;
            case JB_SIZE_T_TYPE: std::cout << node->value.jb_size_t << "\n"; break;
            case JB_CHAR_TYPE: std::cout << node->value.jb_ch << "\n"; break;
            case JB_BOOL_TYPE: std::cout << node->value.jb_bool << "\n"; break;
            case JB_DOUBLE_TYPE: std::cout << node->value.jb_double << "\n"; break;
            case JB_STR_TYPE: std::cout << node->value.jb_str << "\n"; break;
            case JB_VECTOR_STR_TYPE: print_vector(node->value.jb_vect_str, false); break;
            case JB_VECTOR_INT_TYPE: print_vector(node->value.jb_vect_int, false); break;
        }
    }
}

static void getDataParsed(std::vector<std::string> lineVector,std::vector<std::string> parents)
{
    jb_json_t *node = nullptr;

    for (size_t i = 0; i < lineVector.size(); i++) {
        jsonObjType_t value = {};

        if (check_str_last_index(lineVector[i], ':')) {
            lineVector[i] = clearKeyInQuotes(lineVector[i], false);
            if (i + 1 < lineVector.size() && !check_str_last_index(lineVector[i + 1], ':')) {
                std::string path = vector_to_string(parents, "/");
                if (path.size() > 0) {
                    std::cout << path << "/";
                }
            }
            std::cout << lineVector[i];
            std::cout << " => ";
            std::string str;
            bool canStoreString = false;
            for  (; i + 1 < lineVector.size() && !check_str_last_index(lineVector[i + 1], ':'); i++){
                if (check_str_last_index(lineVector[i + 1], ','))
                {
                    lineVector[i + 1].pop_back();
                }
                if (lineVector[i + 1][0] == '\"') {
                    canStoreString = true;
                }
                if (canStoreString) {
                    str += lineVector[i + 1];
                    if (i + 2 < lineVector.size() && !check_str_last_index(lineVector[i + 2], ':')) {
                        str += " ";
                    }
                }
                std::cout << lineVector[i + 1] << " ";
            }
            if (!str.empty()) {
                node = create_jb_json(value, JB_STR_TYPE);
                std::cout << "[" << str << "]\n";
            }
            std::cout << "\n\n";
        }
    }
}

extern void JsonObj::parseDataToJsonObj()
{
    char *line = nullptr;
    std::vector<std::string> parents;
    std::vector<std::string> lineVector;
    std::vector<std::string> parentValidator;

    for (const auto &inData : data) {
        if (!(line = std_str_to_char_str(inData))) {
            return;
        }

        lineVector = str_to_vector(line, " \t\n,{}[]");
        parentValidator = str_to_vector(line, " \t\n,");

        if (check_str_last_index(parentValidator[0], ':') && parentValidator[1][0] == '{') {
            parents.push_back(clearKeyInQuotes(parentValidator[0], false));
        } else if (parentValidator[0][0] == '}') {
            if (parents.size() > 0) {
                parents.pop_back();
            }
        }

        getDataParsed(lineVector, parents);

        free(line);
    }
}
