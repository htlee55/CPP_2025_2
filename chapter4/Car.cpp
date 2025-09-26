#include <iostream>
#include <string>
using namespace std;

class Car {
public:
	// 멤버 변수 선언
	int speed; // 속도
	int gear; // 기어
	string color; // 색상

	 // 멤버 함수 선언
	void speedUp() { // 속도 증가 멤버 함수
		speed += 10;
	}

	void speedDown() { // 속도 감소 멤버 함수
		speed -= 10;
	}
};

nt main()
{
	Car myCar;

	myCar.speed = 100;
	myCar.gear = 3;
	myCar.color = "red";

	myCar.speedUp();
	myCar.speedDown();

	return 0;
}
