Author: Bhuwan KC 


*** CONVEX HULL ***



Method: Graham's Scan

Programming language: C++



Code structure and remarks:

- OOP concept was applied. Two classes namely point and stack were created and used

- The basic code outline follows the pseudo-code mentioned in CLRS
- Separate code file was created to generate desired number of points data type.
- Randomly generated data points are saved in data.txt file

- The convex hull points as computed by the code are saved in export.txt so that it can be exported and plotted

- The graph for a sample data of 25 points were exported and plotted in Excel.

- Makefile was created and can be used for compiling the codes.



Ways to COMPILE:
Go into src folder then do one of the following 
 
To run the code with user input:

1. make

2. ./a.out



To run the code with input from a file:

1. make

2. ./a.out < filename_txt



To run the code with handpicked data:

1. make

2. ./a.out < data_hand_picked.txt

OR
 ./a.out < data_hand_picked_special.txt



To run the code with random data:

1. make random

2. ./a.out x

(Note: x is the number of random data points you want. eg, ./a.out 10. These random data points are stored in data.txt)

3. make 

4. ./a.out < data.txt


