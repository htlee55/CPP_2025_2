#include <iostream>
using namespace std;

class Character {
public:
    string name;
    int hp;

    void printStatus() {
        cout << name << ", HP: " << hp << endl;
    }
};

int main() {
    Character party[3];

    party[0].name = "Knight";
    party[0].hp = 100;

    party[1].name = "Archer";
    party[1].hp = 80;

    party[2].name = "Wizard";
    party[2].hp = 60;

    for (int i = 0; i < 3; i++) {
        party[i].printStatus();
    }

    return 0;
}
