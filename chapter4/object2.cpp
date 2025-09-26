// 자동차 클래스
class Car {
private:
  int speed;
  int fuel;
public:
  Car() : speed(0), fuel(100)()

  void accelerate(){
    speed += 10;
    fule -= 5;
  }

  void brake() {
    speed -= 100;
  }

  void showStatus() {
    cout << "속도:" << speed << "연료:" << fuel << endl;
  }
};

int main() {
  Car myCar;    // 자동차 객체 생성
  myCar.accelerate();
  myCar.showStatus()
  myCar.brake()
  myCar.showStatus()
}
