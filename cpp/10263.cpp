/*
	Code for 10263 - Railway
	Language: C++
	Runtime: 0.000
	Author: Jullytta
	Submitted: 2015-06-20 16:29:59
*/

#include <iostream>
#include <limits>
#include <cmath>
#include <stdio.h>

using namespace std;

struct Point{
	double x, y;
};

Point createPoint(double x, double y);
double distanceToPoint(Point a, Point b, Point m, Point *closestPoint);
double distanceBetweenPoints(Point a, Point b);
double dotProduct(Point a, Point b);

int main(void){

	int n;
	double x, y, minDistance, distance;
	Point m, a, b, p, closestPoint;

	while(cin >> x >> y >> n){

		m = createPoint(x,y);
		minDistance = numeric_limits<double>::max();

		cin >> x >> y;
		b = createPoint(x,y);
		for(int i = 0; i < n; i++){
			a = b;
			cin >> x >> y;
			b = createPoint(x,y);
			distance = distanceToPoint(a, b, m, &p);
			if(distance < minDistance){
				minDistance = distance;
				closestPoint = p;
			}
		}

		printf("%.4f\n%.4f\n", closestPoint.x, closestPoint.y);

	}

	return 0;

}

Point createPoint(double x, double y){
	Point m;
	m.x = x;
	m.y = y;
	return m;
}

double distanceToPoint(Point a, Point b, Point m, Point *closestPoint){

	double t, lengthSquared;
	lengthSquared = (b.y-a.y)*(b.y-a.y)+(b.x-a.x)*(b.x-a.x);
	t = dotProduct(createPoint(m.x-a.x,m.y-a.y), createPoint(b.x-a.x,b.y-a.y))/lengthSquared;
	if(t < 0.0){
		*closestPoint = a;
		return distanceBetweenPoints(m, a);
	}
	else if(t > 1.0){
		*closestPoint = b;
		return distanceBetweenPoints(m, b);
	}
	Point projection = createPoint(a.x + t*(b.x-a.x), a.y + t*(b.y-a.y));
	*closestPoint = projection;
	return distanceBetweenPoints(m, projection);

}

double distanceBetweenPoints(Point a, Point b){
	return sqrt((b.y-a.y)*(b.y-a.y)+(b.x-a.x)*(b.x-a.x));
}

double dotProduct(Point a, Point b){
	return (a.x*b.x + a.y*b.y);
}