// lunar_lander.cpp
#include <SFML/Graphics.hpp>
#include <iostream>
#include <string>

#include "game.hpp"

using namespace sf;
using std::string;

// =======================
// 1) Lander: SFML 모르는 순수 로직
// =======================
class Lander {
private:
    double x, y;       // 위치
    double velocity;   // 속도 (아래로 +)
    double fuel;       // 연료
public:
    Lander(double startX, double startY, double v, double f)
        : x(startX), y(startY), velocity(v), fuel(f) {}

    void update(double thrust, double gravity) {
        // thrust: 위쪽으로 작용하는 힘의 크기 (0 또는 양수)
        if (fuel <= 0.0) {
            fuel = 0.0;
            thrust = 0.0;
        } else {
            fuel -= thrust;          // 단순히 사용량 = thrust (예제용)
            if (fuel < 0.0) fuel = 0.0;
        }

        velocity = velocity - thrust + gravity;
        y += velocity;

        // 바닥에 닿으면 더 내려가지 않도록
        if (y > 450) {
            y = 450;
            velocity = 0.0;
        }
    }

    bool isOnGround() const { return y >= 450; }

    double getX() const { return x; }
    double getY() const { return y; }
    double getVelocity() const { return velocity; }
    double getFuel() const { return fuel; }
};

// =======================
// 2) LanderView: SFML 전담 (그래픽 교체 시 여기만 바꾸면 됨)
// =======================
class LanderView {
private:
    Texture backgroundTex;
    Texture shipTex;
    Texture burstTex;
    Sprite background;
    Sprite ship;
    Sprite burst;
    Font font;
    Text info;

public:
    bool init() {
        if (!backgroundTex.loadFromFile("images/background.png")) {
            std::cout << "배경 이미지 로드 실패\n";
        }
        else {
            background.setTexture(backgroundTex);
        }

        if (!shipTex.loadFromFile("images/spaceship.png")) {
            std::cout << "spaceship.png 로드 실패\n";
            return false;
        }
        if (!burstTex.loadFromFile("images/burst.png")) {
            std::cout << "burst.png 로드 실패\n";
            return false;
        }
        ship.setTexture(shipTex);
        burst.setTexture(burstTex);

        if (!font.loadFromFile("OpenSans-Bold.ttf")) {
            std::cout << "폰트 로드 실패\n";
            return false;
        }
        info.setFont(font);
        info.setCharacterSize(20);
        info.setFillColor(Color::White);

        return true;
    }

    void draw(RenderWindow& window, const Lander& lander, bool thrusting) {
        // 배경
        window.draw(background);

        // 우주선 위치
        double x = lander.getX();
        double y = lander.getY();

        ship.setPosition((float)x, (float)y);
        window.draw(ship);

        // 추력 불꽃 (↑ 키 누를 때만)
        if (thrusting && lander.getFuel() > 0.0) {
            burst.setPosition((float)x + 20.f, (float)y + 50.f);
            window.draw(burst);
        }

        // 상태 텍스트
        string status;
        status += "Press UP key!\n";
        status += "height: " + std::to_string((int)(450 - lander.getY())) + "\n";
        status += "speed : " + std::to_string(lander.getVelocity()) + "\n";
        status += "fuel  : " + std::to_string((int)lander.getFuel());

        info.setString(status);
        info.setPosition(10.f, 20.f);
        window.draw(info);
    }
};

// =======================
// 3) LunarLanderClient: IGameClient 구현
//    - SFML 윈도우 + Lander(로직) + LanderView(그리기)
// =======================
class LunarLanderClient : public IGameClient {
private:
    RenderWindow window;
    Lander lander;
    LanderView view;

    bool running = true;
    bool thrusting = false;

    const double gravity = 0.8;   // 원래 코드와 동일

public:
    LunarLanderClient()
        : window(VideoMode(600, 480), "LUNAR LANDER (refactored)"),
          lander(300.0, 300.0, 1.0, 100.0)
    {
        window.setFramerateLimit(60);
        if (!view.init()) {
            std::cout << "리소스 초기화 실패\n";
        }
    }

    // Game 루프가 사용할 인터페이스 구현

    bool isRunning() const override {
        return running && window.isOpen();
    }

    void handleInput() override {
        // 윈도우 이벤트 처리
        Event e;
        while (window.pollEvent(e)) {
            if (e.type == Event::Closed) {
                running = false;
                window.close();
            }
        }

        // 키보드 입력
        thrusting = Keyboard::isKeyPressed(Keyboard::Up);
    }

    void update(double /*dt*/) override {
        // 단순화를 위해 dt는 무시하고, 원래 코드처럼 고정 값 사용
        double thrustAmount = thrusting ? 3.0 : 0.0;
        lander.update(thrustAmount, gravity);

        if (lander.isOnGround()) {
            // 여기서는 단순히 계속 보여주기만 하고 종료는 안 함
            // running = false;  // 원하면 착륙 시 종료 가능
        }
    }

    void render() override {
        window.clear();
        view.draw(window, lander, thrusting);
        window.display();
    }
};

// =======================
// 4) main: Game + LunarLanderClient 연결
// =======================
int main() {
    LunarLanderClient client;
    Game game(client);
    game.run();
    return 0;
}
