#include"Stack.h"

bool Stack::is_empty()
{
	if(points.size()==0)
		return true;
	return false;
}

void Stack::pop()
{
	if(is_empty())
		return;
	points.pop_back();
}

Point Stack::top()
{
	return points.back();
}

Point Stack::next_to_top()
{
	int a = (points.back()).get_x();
	int b = (points.back()).get_y();
	Point p1 {a,b};
	//Point p1 (points.back());
	pop(); 
	
	a = (points.back()).get_x();
	b = (points.back()).get_y();
	Point p2 {a,b};
	//Point p2 (points.back());
	
	push(p1);
	return p2;
}

void Stack::push(Point p)
{
	points.push_back(p);
}

string Stack::to_string()
{
	string result = "";
	for(Point it: points)
		result+= it.to_string() + "\n";
	
	return result;
}


