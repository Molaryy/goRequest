#include <SFML/Graphics.hpp>
#define WIDTH 1920
#define HEIGHT 1080

class mainApp {
    public:
        sf::VideoMode vMode;
        sf::RenderWindow window;
        sf::Event event;
        sf::Vector2i mousePos;

    void initGame()
    {
        this->vMode = {WIDTH, HEIGHT, 32};
        this->window.create(this->vMode, "goRequest");
    }

    void eventsApp() {
        while (this->window.pollEvent(this->event)) {
            this->mousePos = sf::Mouse::getPosition();
            if (this->event.type == sf::Event::Closed) {
                this->window.close();
            }
        }
    }

    void startApp(sf::CircleShape circle) {
        this->initGame();
        while (this->window.isOpen()) {
            this->eventsApp();
            circle.setPosition((float)this->mousePos.x - 75, (float)this->mousePos.y - 75);
            this->window.clear();
            this->window.draw(circle);
            this->window.display();
        }
    }
};

int main()
{
    mainApp app;
    sf::CircleShape circle(100.f);

    circle.setFillColor(sf::Color::Green);
    app.startApp(circle);
    return 0;
}
