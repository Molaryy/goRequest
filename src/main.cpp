#include "jb_src.hpp"

int initGoRequest()
{
    return (0);
}

class goRequest {
    public:
        std::vector<Button> navBarButtons;

    void initApp(const Button &newButton) {
        this->navBarButtons.emplace_back(newButton);
    }
};

void  checkNavBarButtonsClicked(goRequest *app, sf::Vector2i mousePos)
{
    for (auto &navBarButton : app->navBarButtons) {
        if (navBarButton.isButtonClicked(mousePos)){
            navBarButton.button.setFillColor(sf::Color::Green);
        } else {
            navBarButton.button.setFillColor(sf::Color::Blue);
        }
    }
}

void drawNavBarButtons(sf::RenderWindow *window, goRequest *app)
{
    for (auto &navBarButton : app->navBarButtons) {
        navBarButton.drawRenderWindow(window);
    }
}

void updateRenderWindow(sf::RenderWindow *window, goRequest app)
{
    sf::Event event{};

    while (window->isOpen()){
        while (window->pollEvent(event)){
            sf::Vector2i mousePos = sf::Mouse::getPosition(*window);
            if (event.type == sf::Event::Closed) {
                window->close();
            }
            if (event.type == sf::Event::MouseButtonPressed) {
                checkNavBarButtonsClicked(&app, mousePos);
            }
        }
        window->clear();
        drawNavBarButtons(window, &app);
        window->display();
    }
}

void getJson()
{
    const char *filePath = "data/buttons.json";
    JsonObj json(filePath);

    json.getFile();
}

int main()
{
    /*
     * sf::VideoMode video = {WIDTH, HEIGHT, 32};
    sf::RenderWindow window(video, "Go request");
    Button button((sf::Vector2f){50, 50},(sf::Vector2f){0, 0},sf::Color::Red);
    goRequest app{};
    window.setFramerateLimit(60);

    app.initApp(button);
    updateRenderWindow(&window, app);
     */
    getJson();
    /*std::string str = "123:456:789:ABC:DEF";
    std::cout << str.substr(0, 3) << "\n";
    std::cout << str.substr(4, 7 - 4) << "\n";
    std::cout << str.substr(8, 11 - 8) << "\n";
    std::cout << str.substr(12, 15 - 12) << "\n";
    std::cout << str.substr(16, 19 - 16) << "\n";*/
    return (0);
}
