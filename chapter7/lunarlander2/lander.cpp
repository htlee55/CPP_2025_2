#include "lander.hpp"
#include <SFML/Graphics.hpp>
//#include <windows.h>
//#include <string>
//#include <vector>
#include <iostream>
using namespace sf;
using namespace std;


// 생성자 함수
LunarLander::LunarLander(double h, double v, double f) {
	x = 300;
	y = h;
	velocity = v;
	fuel = f;
	t1.loadFromFile("images/spaceship.png");
	t2.loadFromFile("images/burst.png");
	spaceship.setTexture(t1);
	burst.setTexture(t2);
	spaceship.setPosition(x, y);
	burst.setPosition(x + 20, y + 50);
	if (!font.loadFromFile("OpenSans-Bold.ttf")) {
		cout << "폰트 파일을 오픈할 수 없음!" << endl;
	}
	text.setFont(font);
}
// 착륙했는지를 검사하는 함수. 만약 높이가 0보다 작으면 착륙한 것이다. 
bool LunarLander::checkLanded() {
	if (y <= 0)
		return true;
	return false;
}

// 게임 상태를 업데이트한다. 
void LunarLander::update(double amount) {
	if (fuel <= 0) {
		fuel = 0;
		amount = 0;
	}
	fuel = fuel - amount;
	velocity = velocity - amount + 0.8;		// 하강속도 감속, 중력가속도 0.8
	y = y + velocity;						// 위치 업데이트, y축은 아래로 증가, (속도*시간, 시간=1)
	if (y > 450) y = 450;					// 바닥에 닿으면 y=450으로 고정, 바닥 아래로는 못가게	고정
	spaceship.setPosition(x, y);			// 착륙선 위치 업데이트
	burst.setPosition(x + 20, y + 50);		// 불꽃 위치 업데이트
	status = "Press up key!\nheight: " + to_string(y) + "\nspeed: " + to_string(velocity) + "\nfuel: " + to_string(fuel); // 상태 문자열 업데이트
}

// 화면에 착륙선과 불꽃, 현재 상태를 그린다. 
void LunarLander::draw(RenderWindow& window) {
	window.draw(spaceship);
	window.draw(burst);
	text.setString(status);
	text.setCharacterSize(20);
	text.setPosition(10, 100);
	window.draw(text);
}