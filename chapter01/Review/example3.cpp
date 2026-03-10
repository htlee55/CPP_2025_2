#include <iostream>
using namespace std;

int main() {
    string name = "Knight";
    int hp = 0;

    if (hp <= 0) {
        cout << name << " is dead." << endl;
    } else {
        cout << name << " is alive." << endl;
    }

    return 0;
}
