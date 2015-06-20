/*
	Code for 10263 - Railway
	Language: C++
	Runtime: ?
	Author: Jullytta
	Submitted: ?
*/

#include <iostream>

using namespace std;

struct Point{
	float x, y;
};

Point createPoint(float x, float y);

int main(void){

	int n;
	float x, y;
	Point m, bestPlace, a, b;

	while(cin >> x >> y >> n){

		m = createPoint(x,y);

		for(int i = 0; i < n+1; i++){
			cin >> x >> y;
			a = createPoint(x,y);
//https://en.wikipedia.org/wiki/Distance_from_a_point_to_a_line
		}

	}

	cout << "Hi there!\n";

	return 0;

}

Point createPoint(float x, float y){
	Point m;
	m.x = x;
	m.y = y;
	return m;
}