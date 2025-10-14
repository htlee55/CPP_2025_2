#include <stdio.h>
#include <string.h>

// 자동차 구조체 (데이터만 저장)
typedef struct {
    int speed;      // 속도
    int gear;       // 기어
    char color[20]; // 색상
} Car;

// 속도를 증가시키는 함수 (데이터와 함수가 분리되어 있음)
void speedUp(Car* car) {
    car->speed += 10;
}

// 속도를 감소시키는 함수
void speedDown(Car* car) {
    car->speed -= 10;
}

int main() {
    Car myCar; // 자동차 변수 생성

    // 초기값 설정
    myCar.speed = 100;
    myCar.gear = 3;
    strcpy(myCar.color, "red");

    // 함수 호출 (데이터 따로, 함수 따로)
    speedUp(&myCar);
    speedDown(&myCar);

    // 현재 상태 출력
    printf("Speed: %d, Gear: %d, Color: %s\n",
           myCar.speed, myCar.gear, myCar.color);

    return 0;
}
