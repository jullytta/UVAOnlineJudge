#include<iostream>
#include<sstream>
#include<cmath>
#include<cstdlib>
#include<stdio.h>

const int dimension = 4;
const int velocity = 20;

using namespace std;

int main(void){

	int testCases, x, y, a1, b1, a2, b2, hours, minutes;
	double space;
	string buffer;
	
	getline(cin, buffer);
	
	stringstream ss(buffer);
	
	ss >> testCases;
	
	getline(cin, buffer);
	
	for(int i = 0; i < testCases; i++){
		
		space = 0;
		
		getline(cin, buffer);

		ss.clear();
		ss << buffer;

		ss >> x >> y;
		
		getline(cin, buffer);
			
		ss.clear();
		ss << buffer;
		
		while(!buffer.empty()){

			ss >> a1 >> b1 >> a2 >> b2;
//			cout << "a1 = " << a1 << " b1 = " << b1 << " a2 = " << a2 << " b2 = " << b2 << endl;
			
			space += sqrt(((a2 - a1)*(a2 - a1))+ ((b2 - b1)*(b2 - b1)))*2;
			
//			cout << space << endl;
			
			getline(cin, buffer);
			
			ss.clear();
			ss << buffer;
			
		}
		
		space /= 1000;
		space /= velocity;
		
		hours = floor(space);
		minutes = round((space - floorf(space))*60);
		if(minutes == 60){
			hours++;
			minutes = 0;
		}
		
		printf("%d:%02d\n", hours, minutes);
		
		if(i != testCases-1)
			cout << "\n";
	}

	return 0;
	
}
