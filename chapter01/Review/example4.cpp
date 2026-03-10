#include <iostream>
using namespace std;

int main() {
    string name = "Knight";
    int hp = 100;

    for (int turn = 1; turn <= 5; turn++) {
        hp -= 15;
        cout << "Turn " << turn << ", HP: " << hp << endl;
    }

    return 0;
}
