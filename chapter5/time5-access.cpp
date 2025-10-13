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

	int getHour() { return hour; }
	int getMinute() { return minute; }
	void setHour(int h) { hour = h; }
	void setMinute(int m) { minute = m; }

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
	Time a ( 0, 0 );
  a.setHour(6);
  a.setMinute(30);

	a.print();
	return 0;
}
