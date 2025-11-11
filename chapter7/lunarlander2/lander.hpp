#include <SFML/Graphics.hpp>
#include <windows.h>
#include <string>
#include <vector>
//#include <iostream>
using namespace sf;
using namespace std;	

class LunarLander {
private:
	double x, y;		// 현재 위치
	double velocity;	// 속도
	double fuel;		// 연료
	string status;		// 현재 상태
	Texture t1, t2;		// 텍스처 객체
	Sprite spaceship, burst;	// 스프라이트 객체
	Font font;			// 폰트 객체
	Text text;			// 텍스트 객체
public:
	LunarLander(double h, double v, double f);	// 생성자 함수
	bool checkLanded();							// 착륙 검사 함수
	void update(double rate);					// 상태 업데이트 함수
	void draw(RenderWindow& window);			// 착륙선 그리는 함수
};

