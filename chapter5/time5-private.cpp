#include <iostream>
using namespace std;

class Time {
private:			// 이후에 선언되는 멤버는 모두 전용 멤버가 된다. 
	int hour;		// 0-23
	int minute;		// 0-59
public:
	Time(int h, int m);
	void inc_hour();
	void print();
};

Time::Time(int h, int m) {
	hour = h;
	minute = m;
}

void Time::inc_hour() {
	++hour;
	if (hour > 23)
		hour = 0;
}

void Time::print() {
	cout << hour << “:” << minute << endl;
}

int main()
{
	Time a (24, 59);
  	++a.hour;          //이제는 오류가 발생

  	a.inc_hour();      //안전하게 시간을 증가

	a.print();
	return 0;
}
