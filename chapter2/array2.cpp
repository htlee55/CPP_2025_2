#include <iostream>
#include <stdlib.h>     
using namespace std;

int main() {
	int list[10];
	int max;

	for (int& elem : list)	{
		elem = rand() % 100 + 1;
		cout << elem << " ";
	}
	cout << endl;
	max = list[0];
	for (auto& elem : list)	{
		if (elem > max)
			max = elem;
	}
	cout << "최대값=" << max << endl;
	return 0;
}


