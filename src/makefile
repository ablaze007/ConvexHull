#make file for graham scan 

CXXFLAGS = -std=c++11

executable: graham_scan.o Point.o Stack.o
	$(CXX) $(CXXFLAGS) graham_scan.o Point.o Stack.o
	
random: random_numbers.cpp
	$(CXX) $(CXXFLAGS) random_numbers.cpp
	
debug: graham_scan.o Point.o Stack.o
	$(CXX) $(CXXFLAGS) graham_scan.o Point.o Stack.o -g

graham_scan.o: graham_scan.cpp Point.h Stack.h
	$(CXX) $(CXXFLAGS) -c graham_scan.cpp

Point.o: Point.cpp Point.h
	$(CXX) $(CXXFLAGS) -c Point.cpp
	
Stack.o: Stack.cpp Stack.h
	$(CXX) $(CXXFLAGS) -c Stack.cpp

clean:
	rm -f *.out *.o
	

