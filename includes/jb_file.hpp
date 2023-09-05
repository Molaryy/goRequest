//
// Created by mohammed on 05.09.23.
//

#ifndef _JS_FILE_HPP
    #define _JS_FILE_HPP

class JsonObj {
    public:
        std::vector<std::string> data;

    bool getFile(const char *filePath);
};



#endif /* GOREQUEST_JS_FILE_HPP */
