//
// Created by mohammed on 08.09.23.
//

#ifndef _GOREQUEST_HPP
#define _GOREQUEST_HPP

class GoRequest {
    public:
        GoRequest(uint width, uint height);
        void start();
        void events();
        void draw();
    private:
        sf::VideoMode vMode;
        sf::RenderWindow window;
        sf::Event event;
        sf::Vector2i mousePos;
};


#endif //_GOREQUEST_HPP
