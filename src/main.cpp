#include <SFML/Graphics.hpp>
#include "jb_int.hpp"
#define WIDTH 1920
#define HEIGHT 1080

using namespace sf;
using namespace std;

class mainApp;
void print(mainApp *obj);


class button {
    public:
        RectangleShape button;


    void createButton(Vector2f size, Color fillColor)
    {
        this->button.setSize(size);
        this->button.setFillColor(fillColor);
    }

    void setButtonTexture(Texture *texture)
    {
        this->button.setTexture(texture, false);
    }

    bool isButtonClicked(Vector2i mousePos) {
        Vector2f buttonPos = this->button.getPosition();
        Vector2f buttonSize = this->button.getSize();

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
        VideoMode vMode;
        RenderWindow window;
        Event event{};
        Vector2i mousePos;

    void initGame()
    {
        this->vMode = {WIDTH, HEIGHT, 32};
        this->window.create(this->vMode, "goRequest");
    }

    void eventsApp() {
        while (this->window.pollEvent(this->event)) {
            this->mousePos = Mouse::getPosition();
            if (this->event.type == Event::Closed) {
                this->window.close();
            }
        }
    }

    void startApp(CircleShape circle) {
        this->initGame();
        while (this->window.isOpen()) {
            this->eventsApp();
            circle.setPosition((float)this->mousePos.x - 75, (float)this->mousePos.y - 75);
            this->window.clear();
            this->window.draw(circle);
            this->window.display();
            print(this);
        }
    }
};

void print(mainApp *obj) {
    cout << obj->mousePos.x << "\n";
}

int main(int ac, char **av)
{
    return 0;
}
