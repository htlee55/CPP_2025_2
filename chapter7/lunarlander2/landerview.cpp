// LanderView.cpp
#include "LanderView.hpp"
#include "Lander.hpp"
#include <iostream>

LanderView::LanderView() {}

bool LanderView::load()
{
    if (!bgTex_.loadFromFile("images/background.png")) {
        std::cout << "background.png 로드 실패\n";
        // 배경은 없어도 게임 가능하므로 강제 실패는 안 함
    } else {
        bg_.setTexture(bgTex_);
    }

    if (!shipTex_.loadFromFile("images/spaceship.png")) {
        std::cout << "spaceship.png 로드 실패\n";
        return false;
    }
    ship_.setTexture(shipTex_);

    if (!burstTex_.loadFromFile("images/burst.png")) {
        std::cout << "burst.png 로드 실패\n";
        // 불꽃도 없어도 실행은 가능하니 계속 진행
    } else {
        burst_.setTexture(burstTex_);
    }

    if (!font_.loadFromFile("OpenSans-Bold.ttf")) {
        std::cout << "폰트 로드 실패\n";
        return false;
    }
    text_.setFont(font_);
    text_.setCharacterSize(20);
    text_.setFillColor(sf::Color::White);

    return true;
}

void LanderView::draw(sf::RenderWindow& window,
                      const Lander& lander,
                      bool thrusting)
{
    // 배경
    if (bgTex_.getSize().x > 0)
        window.draw(bg_);

    // 우주선
    ship_.setPosition(
        static_cast<float>(lander.x()),
        static_cast<float>(lander.y())
    );
    window.draw(ship_);

    // 추력 불꽃
    if (thrusting && lander.fuel() > 0.0 && !lander.isOnGround()
        && burstTex_.getSize().x > 0)
    {
        burst_.setPosition(
            static_cast<float>(lander.x()) + 20.f,
            static_cast<float>(lander.y()) + 50.f
        );
        window.draw(burst_);
    }

    // 상태 텍스트 (문자열 생성은 Lander 쪽)
    text_.setString(lander.statusText());
    text_.setPosition(10.f, 20.f);
    window.draw(text_);
}
