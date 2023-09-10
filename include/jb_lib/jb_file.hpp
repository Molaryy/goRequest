//
// Created by mohammed on 05.09.23.
//

#ifndef _JS_FILE_HPP
    #define _JS_FILE_HPP

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
};

#endif /* GOREQUEST_JS_FILE_HPP */
