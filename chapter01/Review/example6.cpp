#include <iostream>
using namespace std;

class Character {
public:
    string name;
    int hp;
    int attack;

    void printStatus() {
        cout << name << ", HP: " << hp << ", Attack: " << attack << endl;
    }

    void takeDamage(int damage) {
        hp -= damage;
        if (hp < 0) hp = 0;
    }
};

int main() {
    Character hero;
    hero.name = "Knight";
    hero.hp = 100;
    hero.attack = 20;

    hero.printStatus();
    hero.takeDamage(30);
    hero.printStatus();

    return 0;
}
