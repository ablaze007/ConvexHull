#include"Point.h"

int Point::get_x()
{
	return x;
}

int Point::get_y()
{
	return y;
}

void Point::set_xy(int a, int b)
{
	x = a;
	y = b;
}

Point& Point::operator=(Point& rhs)
{
	this->set_xy(rhs.get_x(),rhs.get_y());
	return *this;
}

string Point::to_string()
{
	return std::to_string(x)+" "+std::to_string(y);
}

