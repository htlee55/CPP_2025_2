// Lander.hpp
#pragma once
#include <string>

class Lander {
public:
    Lander(double x = 300.0, double y = 300.0,
           double v = 1.0, double fuel = 100.0);

    // thrust: 위 방향 추력(0 또는 양수)
    // 중력은 내부에서 상수로 처리 (원래 예제와 동일한 느낌)
    void update(double thrust);

    bool isOnGround() const;

    double x() const { return x_; }
    double y() const { return y_; }
    double velocity() const { return v_; }
    double fuel() const { return fuel_; }

    // 화면에 표시할 상태 문자열 (여기도 SFML 없음)
    std::string statusText() const;

private:
    double x_;     // 위치
    double y_;
    double v_;     // 속도
    double fuel_;  // 연료
};
