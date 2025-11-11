// Game.hpp
#pragma once
#include <SFML/Graphics.hpp>
#include "lander.hpp"

class Game {
public:
    Game(unsigned w = 600, unsigned h = 480, const char* title = "LUNAR LANDER");
    void run(); // main game loop
private:
    void handleEvents();
    void update(float dt);
    void render();

    sf::RenderWindow window_;
    sf::Clock clock_;
    bool running_ = true;

    LunarLander lander_;   // ? 포인터 말고, LunarLander 객체를 직접 보유
};
