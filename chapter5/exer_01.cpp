/* 
class Point {
private:
  int x, y;
public:
  Point(int x, int y) {
    this->x = x;
    this->y = y;
  }
  ~Point() { }
};
*/
/*
class Point {
private:
  int x, y;
public:
  Point(int x, int y);
  ~Point();
};
Point::Point(int x, int y) {
  this->x = x;
  this->y = y;
}
Point::~Point() { }
*/
/*
class Point {
private:
  int x, y;
public:
  Point(int x, int y) : x{x}, y{y} { }
  ~Point() { }
};
*/
/*
class Point {
private:
  int x, y;
public:
  Point(int x=0, int y=0) : x{x}, y{y} { }
  ~Point() { }
};
*/
