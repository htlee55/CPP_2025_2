// Game.cpp
#include "Game.hpp"

Game::Game(unsigned w, unsigned h, const char* title)
    : window_(sf::VideoMode(w, h), title),
	lander_(300.0, 1.0, 100.0)   // LunarLander 생성자에 초기 높이, 속도, 연료 전달
{
    window_.setFramerateLimit(60);
}

void Game::run() {
    const unsigned targetFPS = 30;
    const float targetFrameTime = 1.0f / static_cast<float>(targetFPS);

    sf::Clock frameClock;
    while (window_.isOpen() && running_) {
        frameClock.restart();

        handleEvents();

        float dt = clock_.restart().asSeconds();
        update(dt);
        render();

        // 프레임 제한: 남은 시간만큼 대기
        float frameTime = frameClock.getElapsedTime().asSeconds();
        if (frameTime < targetFrameTime) {
            sf::sleep(sf::seconds(targetFrameTime - frameTime));
        }
    }
}

void Game::handleEvents() {
    sf::Event e;
    while (window_.pollEvent(e)) {
        if (e.type == sf::Event::Closed) {
            window_.close();
            running_ = false;
        }
    }
}

void Game::update(float dt) {
    // 입력 기반 기본 추진력(원래는 3.0),↑ 키면 추진력 3.0, 아니면 0.0 (삼항연산자
    double userThrust = sf::Keyboard::isKeyPressed(sf::Keyboard::Up) ? 3.0 : 0.0;
    // 옵션 A: 더 강한 추력으로 변경하려면 userThrust를 늘리세요 (예: 5.0)
    // userThrust = sf::Keyboard::isKeyPressed(sf::Keyboard::Up) ? 5.0 : 0.0;

    // 옵션 B: 항상 적용할 약한 보정 추력 (자동 안정화)
    double baseThrust = 0.0; // 예: 0.3 을 넣으면 상시 약한 추력 적용 (연료 소모 증가)
    baseThrust = 0.3;

    // 옵션 C: 프레임 독립 보정 (60FPS 기준)
    double amount = (userThrust + baseThrust) * (dt * 30.0);

    // 그대로 현재 lander 구현에 전달
    lander_.update(amount);
}

void Game::render() {
    window_.clear();
    lander_.draw(window_);   // LunarLander가 자기 그리기 담당
    window_.display();
}
