// Game.hpp
#pragma once
#include <SFML/Graphics.hpp>
#include <memory>

class Game {
public:
    Game(unsigned w=600, unsigned h=480, const char* title="LUNAR LANDER");
    void run(); // main loop
private:
    void handleEvents();
    void update(float dt);
    void render();

    sf::RenderWindow window_;
    sf::Clock clock_;
    bool running_ = true;
};
