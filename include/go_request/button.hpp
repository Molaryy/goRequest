//
// Created by mohammed on 08.09.23.
//

#ifndef GOREQUEST_BUTTON_HPP
    #define GOREQUEST_BUTTON_HPP


class Button {
    public:
        sf::RectangleShape button;
    
    Button(sf::Vector2f size, sf::Color fillColor);
    void setButtonTexture(sf::Texture *texture);
    bool isButtonClicked(sf::Vector2i mousePos);
};

#endif //GOREQUEST_BUTTON_HPP
