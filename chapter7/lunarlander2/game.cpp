// Game.cpp
#include "Game.hpp"
Game::Game(unsigned w, unsigned h, const char* title)
: window_(sf::VideoMode(w,h), title) { window_.setFramerateLimit(60); }

void Game::run() {
    while (window_.isOpen() && running_) {
        handleEvents();
        float dt = clock_.restart().asSeconds();
        update(dt);
        render();
    }
}

void Game::handleEvents() {
    sf::Event e;
    while (window_.pollEvent(e)) {
        if (e.type == sf::Event::Closed) window_.close();
        // TODO: per-lab input
    }
}
void Game::update(float dt) { /* TODO */ }
void Game::render() { window_.clear(); /* draw... */ window_.display(); }
