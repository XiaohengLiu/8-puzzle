#include <iostream>
#include <fstream>
#include <iomanip>
#include <ctime>

#include "xb.h"
#include "bfs.h"
#include "tastar.h"
		
using namespace std;

int main()  
{  
	clock_t start,finish;
	double durationa,durationb;
	TBFS tbfs("eight.txt");
	TAstar aStar("eight.txt","eight_dis.txt");
	cout<<"astar:"<<endl;
	start = clock(); 
	aStar.Search();
	finish = clock();
	durationa = (double)(finish - start) *1000/ CLOCKS_PER_SEC;
	cout<<"astar time: "<<durationa<<endl;
	cout<<"BFS:"<<endl;
	start = clock();
	tbfs.Search(); 
	finish = clock();
	durationb = (double)(finish - start) *1000/ CLOCKS_PER_SEC;
	
	cout<<"bfs time: "<<durationb<<endl;
	return 0; 
	 
}  


