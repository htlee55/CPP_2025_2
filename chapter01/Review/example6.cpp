#include <iostream>
#include <string>
using namespace std;

class Car {
private:
    string brand;
    int year;

public:
    Car(string b, int y) : brand(b), year(y) {}

    void displayInfo() {
        cout << year << " " << brand << endl;
    }
};

int main() {
    Car myCar("Toyota", 2022);
    myCar.displayInfo();   // 출력: 2022 Toyota
    return 0;
}
