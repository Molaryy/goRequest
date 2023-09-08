#include "jb_src.hpp"

Button::Button(sf::Vector2f size, sf::Color fillColor)
{
    sf::RectangleShape button;
    this->button = button;
    this->button.setSize(size);
    this->button.setFillColor(fillColor);
}

void Button::setButtonTexture(sf::Texture *texture)
{
    this->button.setTexture(texture, false);
}

bool Button::isButtonClicked(sf::Vector2i mousePos)
{
    sf::Vector2f buttonPos = this->button.getPosition();
    sf::Vector2f buttonSize = this->button.getSize();
    if (static_cast<float>(mousePos.x) >= buttonPos.x
    && static_cast<float>(mousePos.x) <= (buttonPos.x - buttonSize.x)
    && static_cast<float>(mousePos.y) >= buttonPos.y
    && static_cast<float>(mousePos.y) <= (buttonPos.y + buttonSize.y)) {
        return true;
    }
    return false;
}
