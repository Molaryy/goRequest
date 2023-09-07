//
// Created by mohammed on 05.09.23.
//

#ifndef _JS_FILE_HPP
    #define _JS_FILE_HPP

class JsonObj {
    public:
        char *filePath;
        std::vector<std::string> data;

    JsonObj(char *filePath);
    bool getFile();
};



#endif /* GOREQUEST_JS_FILE_HPP */
