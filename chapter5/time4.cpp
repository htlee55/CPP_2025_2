#include <iostream>
using namespace std;

class Time {
public:
	int hour;		// 0-23
	int minute;		// 0-59

	Time() {
		hour = 0;
		minute = 0;
	}
	Time(int h, int m) {
		hour = h;
		minute = m;
	}
	void print() {
		cout << hour << ":" << minute << endl;
	}
};
