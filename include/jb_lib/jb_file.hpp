//
// Created by mohammed on 05.09.23.
//

#ifndef _JS_FILE_HPP
    #define _JS_FILE_HPP

enum {
    JB_INT_TYPE = 0,
    JB_SIZE_T_TYPE = 1,
    JB_CHAR_TYPE = 2,
    JB_BOOL_TYPE = 3,
    JB_DOUBLE_TYPE = 4,
    JB_STR_TYPE = 5,
    JB_VECTOR_STR_TYPE = 6,
    JB_VECTOR_INT_TYPE = 7,
};

typedef struct jsonObjType_s {
    char *path;
    bool isParent;
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


/**
* @brief JsonObj class that handles json files
* @class JsonObj
*/
class JsonObj {
    public:
        const char *filePath;
        std::vector<std::string> data;

    /**
    * @brief constructor of the JsonObj
    * @param const char *filePath
    * @class JsonObj
    */
    explicit JsonObj(const char *filePath);

    /**
    * @brief gets the content in the file and pushes all the lines in std::vector<std::string> data
    * @class JsonObj
    * @return true if the filePath given exists else returns false
    */
    bool getFile();

    /**
    * @brief parses the std::vector<std::string> data into a json type key value
    * @class JsonObj
    */
    void parseDataToJsonObj();
};

/**
* @brief gets the content of a file
* @param const char *filePath
* @returns buffer of nullptr if something went wrong
*/
extern char *get_file_content(const char *filepath);

/**
* @brief gets the content of .env
* @param const char *key
* @returns content of the key value
*/
extern char *env_value(const char *key);

#endif /* _JS_FILE_HPP */
