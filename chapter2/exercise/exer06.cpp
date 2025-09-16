#include <iostream>
using namespace std;
int main()
{
	for (int i = 1; i <= 7; i++) {
		int j;
		for (j = 1; j <= i; j++) {
			cout << j;
		}
		for (int k = j; k <= 7; k++) {
			cout << "*";
		}
		cout << endl;
	}
	return 0;
}
