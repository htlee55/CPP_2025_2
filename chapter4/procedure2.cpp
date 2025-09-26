//자동차 운전 절차
int speed = 0;
int fuel = 100;

void accelerate() {
  speed += 10;
  fuel -= 5;
}

void brake(){
  speed -= 10;
}

int main(){
  accelerate();    //가속
  brake();          //브레이크
}
