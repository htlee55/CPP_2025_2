// LanderView.hpp
#pragma once
#include <SFML/Graphics.hpp>
#include <string>

class Lander;

class LanderView {
public:
    LanderView();

    // 리소스 로드 (텍스처, 폰트 등)
    bool load();

    // 하나의 함수로 "그리기"
    void draw(sf::RenderWindow& window,
              const Lander& lander,
              bool thrusting);

private:
    sf::Texture bgTex_;
    sf::Sprite  bg_;

    sf::Texture shipTex_;
    sf::Sprite  ship_;

    sf::Texture burstTex_;
    sf::Sprite  burst_;

    sf::Font font_;
    sf::Text text_;
};
