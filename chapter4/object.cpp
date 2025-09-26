#include <iostream>
#include <string>
using namespace std;

class Student {
    string name;
    int score1, score2;
public:
    Student(string n, int s1, int s2) : name(n), score1(s1), score2(s2) {}
    int average() { return (score1 + score2) / 2; }
    void print() {
        cout << name << " avg = " << average() << endl;
    }
};

int main() {
    Student s("Kim", 90, 80);
    s.print();
    return 0;
}
