// Lander.cpp
#include "Lander.hpp"
#include <string>

namespace {
    constexpr double GROUND_Y = 450.0;
    constexpr double GRAVITY  = 0.8;  // 원래 코드와 같은 값
}

Lander::Lander(double x, double y, double v, double fuel)
    : x_(x), y_(y), v_(v), fuel_(fuel)
{
}

void Lander::update(double thrust)
{
    if (fuel_ <= 0.0) {
        fuel_ = 0.0;
        thrust = 0.0;
    } else {
        fuel_ -= thrust;
        if (fuel_ < 0.0) fuel_ = 0.0;
    }

    v_ = v_ - thrust + GRAVITY;
    y_ += v_;

    if (y_ > GROUND_Y) {
        y_ = GROUND_Y;
        v_ = 0.0;
    }
}

bool Lander::isOnGround() const
{
    return y_ >= GROUND_Y;
}

std::string Lander::statusText() const
{
    double height = GROUND_Y - y_;
    std::string s;
    s += "Press UP key!\n";
    s += "height: " + std::to_string((int)height) + "\n";
    s += "speed : " + std::to_string(v_) + "\n";
    s += "fuel  : " + std::to_string((int)fuel_);
    return s;
}
