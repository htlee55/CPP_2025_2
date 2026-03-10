#include <iostream>
#include <vector>
using namespace std;

class Character {
public:
    string name;
    int hp;

    Character(string n, int h) {
        name = n;
        hp = h;
    }

    void printStatus() {
        cout << name << ", HP: " << hp << endl;
    }
};

int main() {
    vector<Character> party;

    party.push_back(Character("Knight", 100));
    party.push_back(Character("Archer", 80));
    party.push_back(Character("Wizard", 60));

    for (int i = 0; i < party.size(); i++) {
        party[i].printStatus();
    }

    return 0;
}
