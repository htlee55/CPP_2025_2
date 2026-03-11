#include <iostream>
using namespace std;

int main() {
    string name = "Knight";
    int hp = 100;
    int attack = 20;

    cout << "Name: " << name << endl;
    cout << "HP: " << hp << endl;
    cout << "Attack: " << attack << endl;

    float pi = 3.14f;       // f 접미사 권장 (없으면 double로 인식됨)
    float gravity = 9.8F;   // F 대문자도 가능
    float small = 1.2e-3f;  // 지수 표기법 (0.0012)

    cout << pi << ", " << gravity << std::endl;

    return 0;
}
