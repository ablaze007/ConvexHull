
#ifndef POINT_H
#define POINT_H

#include<string>
using namespace std;

class Point
{
public:
	Point(int a, int b): x{a}, y{b} {};

	//Point(Point& rhs): x{rhs.get_x()}, y{rhs.get_y()} {};
	Point& operator=(Point& rhs);
	int get_x();
	int get_y();
	void set_xy(int,int);
	string to_string();

private:
	int x;
	int y;
};

#endif
