#include <iostream>
#include <string>
using namespace std;

class Animal {
protected:
    string name;

public:
    Animal(string n) : name(n) {}

    virtual void makeSound() = 0;   // 순수 가상 함수
};

class Dog : public Animal {
public:
    Dog(string n) : Animal(n) {}

    void makeSound() override {
        cout << name << " says: Woof!" << endl;
    }
};

class Cat : public Animal {
public:
    Cat(string n) : Animal(n) {}

    void makeSound() override {
        cout << name << " says: Meow!" << endl;
    }
};

int main() {
    Dog d("Buddy");
    Cat c("Kitty");

    d.makeSound();
    c.makeSound();

    return 0;
}
