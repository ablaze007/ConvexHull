//Graham scan for convex hull

#include<iostream>
#include"Point.h"
#include"Stack.h"
#include<cmath>
#include<fstream>

//a function to find point with minimum y coordinate
Point get_point_with_min_y(vector<Point>& p)
{
	int min_y = p.front().get_y();
	Point my_point = p.front();
	
	for(Point it: p)
	{
		if(it.get_y() < min_y)
		{
			min_y = it.get_y();
			my_point = it;
		}
		else if(it.get_y()==min_y) //if minimum y values are equal choose one with lesser x
		{
			if(it.get_x()<my_point.get_x())
				my_point = it;
		}
	}
	
	return my_point;
}

//a function to find angle made by p1p2 line with x-axis
double get_angle(Point p1, Point p2)
{
	if(p1.get_x() == p2.get_y() && p1.get_y() == p2.get_y())
		return 0;
		
	double angle;
	double diff_x = (double)((p2.get_x() - p1.get_x()));
	double diff_y = (double)((p2.get_y() - p1.get_y()));
	
	if(diff_x == 0)
		if(diff_y > 0)
			return 11.0/7.0;
		else
			return 33.0/7.0;
	if(diff_y == 0)
		if(diff_x > 0)
			return 0;
		else
			return 22.0/7.0;

	angle = atan(diff_y/diff_x);
	
	//angle adjustment for tan function
	if(diff_x < 0 || diff_x == -0)	//for second and third quadrant
		angle += 22.0/7.0;
	else if(diff_y<0 || diff_y == -0)	//for fouth quadrant
		angle = 44.0/7.0 + angle;
	
	return angle;
}

//a function to calculate polar angles and return in a vector
vector<double> get_polar_angles(vector<Point>& p, Point p_min)
{
	vector<double> result;
	
	for(int i=0; i<p.size(); i++)
	{
		if(p.at(i).get_x() == p_min.get_x() && p.at(i).get_y() == p_min.get_y())
		{
			result.push_back(0);
			continue;
		}
			
		Point x = p.at(i);
		double value = get_angle(p_min,x);
		result.push_back(value);
	}
	
	return result;
}

//a function to find max double in a vector
double get_max(vector<double> d)
{
	double max = d.front();
	for(double it: d)
	{
		if(it>max)
			max = it;
	}
	return max;
}

// a funtion to merge two sorted arrays
void merge(vector<Point>* p,vector<double>* d,int a,int mid, int b)
{
	vector<Point> point_temp1;
	vector<Point> point_temp2;
	vector<double> values_temp1;
	vector<double> values_temp2;
	
	//setting up temporary vectors with the required values
	for(int i=a; i<=mid; i++)
	{
		point_temp1.push_back(p->at(i));
		values_temp1.push_back(d->at(i));
	}
	
	for(int j=mid+1; j<=b; j++)
	{
		point_temp2.push_back(p->at(j));
		values_temp2.push_back(d->at(j));
	}
	
	double max;
	double max1 = get_max(values_temp1) + 1;
	double max2 = get_max(values_temp2) + 1;
	if(max1>max2)
		max = max1;
	else
		max = max2;
	values_temp1.push_back(max);
	values_temp2.push_back(max);
	
	int m = 0;
	int n = 0;
	for(int k=a; k<=b; k++)
	{
		if(values_temp1.at(m) <= values_temp2.at(n))
		{
			d->at(k) = values_temp1.at(m);
			p->at(k) = point_temp1.at(m);
			m++;
		}
		else
		{
			d->at(k) = values_temp2.at(n);
			p->at(k) = point_temp2.at(n);
			n++;
		}
	}
		
}

//to merge sort given vector
void merge_sort(vector<Point>* p, vector<double>* d,int a, int b)
{
	if(a>=b)
		return;
	int mid = (a+b)/2;
	merge_sort(p,d,a,mid);
	merge_sort(p,d,mid+1,b);
	merge(p,d,a,mid,b);
}

//a function to find distance between two points
double distance_between(Point p1, Point p2)
{
	double a = (double)pow(p2.get_y() - p1.get_y(), 2);
	double b = (double)pow(p2.get_x() - p1.get_x(), 2);
	return sqrt(a+b);
}

//a function to delete repeated items from vectors
void remove_repeated_values(vector<Point>* p, vector<double>* d, Point p_min)
{
	for(int i=2; i<p->size(); i++)
	{
		if(d->at(i) == d->at(i-1))
		{
			double d1 = distance_between(p_min,p->at(i));
			double d2 = distance_between(p_min,p->at(i-1));
			if(d1>d2)
			{
				d->erase(d->begin()+(i-1));
				for(int k=i-1; k<p->size()-1; k++)
					p->at(k) = p->at(k+1);
				p->pop_back();
			}
			else
			{
				d->erase(d->begin()+i);
				for(int k=i; k<p->size()-1; k++)
					p->at(k) = p->at(k+1);
				p->pop_back();
			}
			--i;
		}
	}

}		

bool left_turn(Point p1, Point p2, Point p3)
{
	double angle, angle2;
	double adjust;
	//caculate angle made by line p1p2 with x-axis
	angle = get_angle(p1,p2);
	
	//caculate angle made by line p1p3 with x-axis
	angle2 = get_angle(p1,p3);

	//////////////// left turn check /////////////////
	/*cout<<endl<<"P1 = "<<p1.to_string()<<" / "<<"P2 = "<<p2.to_string()<<" / "<<"P3 = "<<p3.to_string() << " - "<< angle << " - "<< angle2<<endl;*/
	
	if(angle2 >= angle)
		return true;
	else
		return false;
}	

//******************************************************
//******************** MAIN ****************************
//******************************************************		
int main()
{
	Stack stack; //creating a empty stack
	vector<Point> points; //to store input points
	int x,y, number;
	
	cin>>number; //total number of points
	//get points from the user
	for(int i=0; i<number; i++)
	{
		cin>>x>>y;
		Point p {x,y};
		points.push_back(p);
	}	
	cout<<endl<<"~~~ All input points ~~~"<<endl;
	for(Point p: points)
	{
		cout<<p.to_string()<<endl;
	}
	
	//find the point with minimum y cordinate 
	Point p_min = get_point_with_min_y(points);
	
	cout<<endl<<"MIN: "<<p_min.to_string()<<endl;  /////////////////////////////
	
	//find the polar angles for all the remaining points w.r.t. p_min
	vector<double> polar_angles = get_polar_angles(points, p_min);
	
	
	////////////////////////test for polar angles///////////////////////
	/*cout<<"Values and points"<<endl;
	for(int i = 0; i<points.size(); i++)
	{
		cout<<polar_angles.at(i)<<" - "<<points.at(i).to_string()<<endl;
	} */
	
	//sort the points based on their polar angle w.r.t p_min
	merge_sort(&points,&polar_angles,0,points.size()-1);
	
	///////////////////test for sorted values///////////////////
	/*cout<<endl<<"After sorting"<<endl;
	for(int i = 0; i<points.size(); i++)
	{
		cout<<polar_angles.at(i)<<" - "<<points.at(i).to_string()<<endl;
	}*/
	
	//remove the repeated point from the vector
	remove_repeated_values(&points,&polar_angles, p_min);
	
	/////////////////////test for removal of repeatative values/////////////
	/*cout<<endl<<"After removing"<<endl;
	for(int i = 0; i<points.size(); i++)
	{
		cout<<polar_angles.at(i)<<" - "<<points.at(i).to_string()<<endl;
	}*/	
	
	if(points.size()<3)
		cout<<endl<<"Error! At least 3 points need to be non collinear\nExiting..."<<endl<<endl;
	else	
	{
	stack.push(points.at(0));
	stack.push(points.at(1));
	stack.push(points.at(2));
	
	//collect Convex Hull points in the stack
	for(int i = 3; i<points.size(); i++)
	{
		while(!left_turn(stack.next_to_top(),stack.top(),points.at(i)))
		{
			//cout<<"POPPED - "<<stack.top().to_string()<<endl;
			stack.pop();
		}
		stack.push(points.at(i));
		//cout<<"PUSHED - "<<points.at(i).to_string()<<endl;
	}
	
	cout<<endl<<"~~~ CONVEX HULL POINTS ~~~"<<endl;
	cout<<stack.to_string()<<endl;
	
	ofstream myfile("export.txt");
	if(myfile.is_open())
	{
		myfile<<stack.to_string();
	}
	myfile.close();
	}
				
	return 0;
}






