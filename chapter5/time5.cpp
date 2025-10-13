#include <iostream>
using namespace std;

class Time {
public:
	int hour;		// 0-23
	int minute;		// 0-59

	Time(int h=0, int m=0) {
		hour = h;
		minute = m;
	}

	void print() {
		cout << hour << ":" << minute << endl;
	}
};

int main()
{
	Time a;					// 매개변수가 없는 생성자 호출
	Time b(10, 25); 		// 매개변수가 있는 생성자 호출

	a.print();
	b.print();
	return 0;
}
