#include"Point.h"
#include<vector>

using namespace std;

class Stack
{
public:
	Stack() {};
	
	bool is_empty();
	void pop();
	Point top();
	Point next_to_top();
	void push(Point);
	string to_string();
	
private:
	vector<Point> points;
};
