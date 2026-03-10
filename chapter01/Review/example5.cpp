#include <iostream>
using namespace std;

int applyDamage(int hp, int damage) {
    hp -= damage;
    return hp;
}

void printStatus(string name, int hp) {
    cout << name << ", HP: " << hp << endl;
}

int main() {
    string name = "Knight";
    int hp = 100;

    hp = applyDamage(hp, 20);
    printStatus(name, hp);

    hp = applyDamage(hp, 30);
    printStatus(name, hp);

    return 0;
}
