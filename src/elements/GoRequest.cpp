#include "jb_src.hpp"

GoRequest::GoRequest(uint width, uint height)
{
    this->vMode = {width, height, 32};
    this->window.create(this->vMode, "goRequest");
}

void GoRequest::start()
{
    while (this->window.isOpen()) {
        this->events();
        this->window.clear(sf::Color::Red);
        this->window.display();
        this->draw();
    }
}

void GoRequest::events()
{
    while (this->window.pollEvent(this->event)) {
        this->mousePos = sf::Mouse::getPosition();
        if (this->event.type == sf::Event::Closed) {
            this->window.close();
        }
    }
}

void GoRequest::draw()
{

}
