/*
	Code for 11909 - Soya Milk
	Language: C++
	Runtime: 0.000
	Author: Jullytta
	Submitted: 2015-06-20 20:08:43
*/

#include <iostream>
#include <cmath>
#include <stdio.h>

using namespace std;

const double pi = 3.141592653589793;

double degreesToRadians(double degrees);

int main(void){

	double l, w, h, o, x, result;

	while(cin >> l >> w >> h >> o){
		x = l*tan(degreesToRadians(o));

		// Careful with case l < h or o > 45
		if(x <= h){
			result = w*l*(h - x/2);
		}
		else {
			o = 90 - o;
			x = h*tan(degreesToRadians(o));
			result = w*h*x/2;
		}
		printf("%.3f mL\n", result);
	}

	return 0;

}

double degreesToRadians(double degrees){
	return degrees*pi/180.0;
}