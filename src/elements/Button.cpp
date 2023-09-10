#include "jb_src.hpp"

Button::Button(sf::Vector2f size, sf::Vector2f pos,sf::Color fillColor)
{
    this->button.setSize(size);
    this->button.setFillColor(fillColor);
    this->button.setPosition(pos);
}

void Button::setButtonTexture(sf::Texture *texture)
{
    this->button.setTexture(texture, false);
}

void Button::setButtonOutlineColor(sf::Color color, float thickness)
{
    this->button.setOutlineColor(color);
    this->button.setOutlineThickness(thickness);
}

bool Button::isButtonClicked(sf::Vector2i mousePos)
{
    sf::Vector2f buttonPos = this->button.getPosition();
    sf::Vector2f buttonSize = this->button.getSize();

    if ((float )(mousePos.x) >= buttonPos.x
        && (float)(mousePos.x) <= (buttonPos.x + buttonSize.x)
        && (float)(mousePos.y) >= buttonPos.y
        && (float)(mousePos.y) <= (buttonPos.y + buttonSize.y)) {
        return true;
    }
    return false;
}

void Button::drawRenderWindow(sf::RenderWindow *window)
{
    window->draw(this->button);
}
