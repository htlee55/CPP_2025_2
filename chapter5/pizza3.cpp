#include <iostream>
using namespace std;

class Pizza {
public:
	Pizza(int s) : size(s) { }
	int size;			// 단위: 인치
};

Pizza createPizza() {
	Pizza p(10);
	return p;
}

int main() {
	Pizza pizza = createPizza();
	cout << pizza.size << "인치 피자" << endl;

	return 0;
}
