/*
	Code for 1388 - Graveyard
	Language: C++
	Runtime: 0.000
	Author: Jullytta
	Submitted: 2015-06-27 01:54:40
*/

/*
	Keep an statue at point 0. Now calculate where the other statues should be and save it on a vector.
	Then for each statue we need to move, use binary search to find the closest free spot.
*/

#include <iostream>
#include <stdio.h>
#include <vector>
#include <complex>
#include <iomanip>

using namespace std;

const int maxN = 1000;
const int precision = 8;
const double alleyLength = 10000;

double searchCloser(double d);
void printDouble(double x);

vector<double> newPositions;

int main(void){

	int n, m;
	double minDistance, oldEquiDistance, newEquiDistance, d;
	cout << setprecision(precision);

	while(cin >> n >> m){
		minDistance = 0;
		oldEquiDistance = alleyLength/n;
		newEquiDistance = alleyLength/(n+m);
		newPositions.clear();

		for(int i = 1; i <= (n+m)-1; i++)
			newPositions.push_back(newEquiDistance*i);

		for(int i = 1; i <= n-1; i++){
			d = searchCloser(oldEquiDistance*i);
			minDistance += abs(d-(oldEquiDistance*i));
		}
		
		cout << minDistance;
		if(minDistance - (int) minDistance <= 0.00001)
			cout << ".0";
		cout << endl;

	}

	return 0;

}

double searchCloser(double d){

	double best = alleyLength;
	int left, right, mid, length;
	length = newPositions.size();
	left = 0;
	right = length;
	while(left < right){
		mid = left + (right-left)/2;
		if(newPositions[mid] < d){
			left = mid+1;
		}
		else
			right = mid;
	}

	if(left != 0 && abs(newPositions[left-1]-d) < abs(best-d))
		best = newPositions[left-1];
	if(abs(newPositions[left]-d) < abs(best-d))
		best = newPositions[left];
	if(left+1 != length && abs(newPositions[left+1]-d) < abs(best-d))
		best = newPositions[left+1];

	return best;

}

void printDouble(double x){
	int y = floor(x);
	cout << "double x = " << x << " and int y = " << y << " so x-y = " << x-y << endl;
	x -= y;
	x *= precision;
	int z = round(x);
	if(z != 0){
		while(!z%10) z /= 10;
	}	
	cout << y << "." << z;
}