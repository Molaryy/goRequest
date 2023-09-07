#include <SFML/Graphics.hpp>
#include <iostream>
#include "jb_src.hpp"
#define WIDTH 1920
#define HEIGHT 1080


class mainApp;
void print(mainApp *obj);


class Colors {
    public:
        sf::Color red;

};

class Button {
    public:
        sf::RectangleShape button;


    void createButton(sf::Vector2f size, sf::Color fillColor)
    {
        this->button.setSize(size);
        this->button.setFillColor(fillColor);
    }

    void setButtonTexture(sf::Texture *texture)
    {
        this->button.setTexture(texture, false);
    }

    bool isButtonClicked(sf::Vector2i mousePos)
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
};

class mainApp {
    public:
        sf::VideoMode vMode;
        sf::RenderWindow window;
        sf::Event event{};
        sf::Vector2i mousePos;
        Button *buttons;

    void initGame()
    {
        this->vMode = {WIDTH, HEIGHT, 32};
        this->window.create(this->vMode, "goRequest");
    }

    void eventsApp()
    {
        while (this->window.pollEvent(this->event)) {
            this->mousePos = sf::Mouse::getPosition();
            if (this->event.type == sf::Event::Closed) {
                this->window.close();
            }
        }
    }

    void drawApp()
    {

    }
    void startApp()
    {
        this->initGame();
        while (this->window.isOpen()) {
            this->eventsApp();
            this->window.clear();
            this->window.display();
            print(this);
        }
    }
};

void print(mainApp *obj)
{
    std::cout << obj->mousePos.x << "\n";
}


int main() {
    mainApp app;

    app.initGame();
    app.startApp();

    return 0;
}