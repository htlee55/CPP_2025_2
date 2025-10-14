#include <iostream>
#include <string>
using namespace std;

class Car {
public:		// 접근지정자
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

int main()
{
	// 객체 생성
	Car myCar;				// myCar는 Car 클래스의 자료형을 가진 변수이다.

	myCar.speed = 100;		// 체의 멤버 접근, 토트(.) 연산자 사용
	myCar.gear = 3;
	myCar.color = "red";

	myCar.speedUp();
	myCar.speedDown();

	return 0;
}
