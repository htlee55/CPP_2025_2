#include <iostream>
using namespace std;

class Rectangle {
	int width, height;
public:
	Rectangle(int w, int h);
	int calcArea();
};

Rectangle::Rectangle(int w, int h) 
{
	width = w;
	height = h;
}

int Rectangle::calcArea() 
{
	return width*height;
}

