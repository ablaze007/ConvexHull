#include<iostream>
#include<cstdlib>
#include<ctime>
#include<fstream>
#include<sstream>

using namespace std;

int main(int argc, char** argv)
{
	srand(time(0));
	int count;
	stringstream convertor(argv[1]);
	convertor >> count;
		
	ofstream myfile("data.txt");
	if(myfile.is_open())
	{
		myfile<<count;
		myfile<<"\n";
		for(int i=0; i<count; i++)
		{
			myfile<<((rand()%200)-100);
			myfile<<" ";
			myfile<<((rand()%200)-100);
			if(i!=count-1)
		 		myfile<<"\n";
		}
	}
	myfile.close();
}

