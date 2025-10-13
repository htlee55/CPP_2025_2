#include <iostream>
using namespace std;

class Time {
public:
	int hour;		// 시를 나타낸다. 0-23가 가능하다.
	int minute;		// 분을 나타낸다. 0-59가 가능하다. 

	void print() {
		cout << hour << ":" << minute << endl;
	}
};

Time a;			// 객체 a를 생성한다. 

a.hour = 26;		
a.minute = 70;
