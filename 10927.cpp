/*
	Code for 10927 - Bright lights
	Language: C++
	Runtime: ?
	Author: Jullytta
	Submitted: ?
*/

/*
	Comparing the poles based on their angle turned out to be a bad idea.
	At least 1e-10 of error precision should be applied to get AC. 
*/

#include <iostream>
#include <vector>
#include <map>
#include <cmath>
#include <set>
#include <iomanip>

using namespace std;

const int maxN = 100000;
const int maxCoord = 10000;
const long range = 10000000000;
const double error = 1e-10;

struct Pole{
	double x, y, z, distance;
};

struct comparePoles {
    bool operator()(const Pole & a, const Pole & b) {
        return ( a.x<b.x || (a.x==b.x && a.y<b.y) );
    }
};

Pole createPole(double x, double y, double z, double distance);
double distanceToTotem(double x, double y);

// I can't find a way to keep only unique poles in a set. Some of them are missing. SOS
set<Pole, comparePoles> notVisibleLights;
map< double, vector<Pole> > polesByAngle;
set<double> angles;

int main(void){

	int nPoles, caseNum;
	double x, y, z, angle;
	Pole p;

	caseNum = 0;
	cin >> nPoles;

	while(nPoles){
		caseNum++;
		notVisibleLights.clear();
		polesByAngle.clear();
		angles.clear();

		for(int i = 0; i < nPoles; i++){
			cin >> x >> y >> z;
			p = createPole(x,y,z,distanceToTotem(x,y));
			angle = atan2(x, y);
			for(set<double>::iterator it = angles.begin(); it != angles.end(); it++){
				if(abs(angle-(*it)) <= error)
					angle = (*it);
				else if((*it) > angle) break;
			}
			polesByAngle[angle].push_back(p);
			for(vector<Pole>::iterator it = polesByAngle[angle].begin(); it != polesByAngle[angle].end(); it++){
				if((*it).distance < p.distance){
					if((*it).z >= p.z){
						notVisibleLights.insert(p);
						angles.insert(angle);
					}
				}
				else if((*it).distance != p.distance && (*it).z <= p.z){
					notVisibleLights.insert(*it);
					angles.insert(angle);
				}
			}
			
		}
		cout << "Data set " << caseNum << ":\n";
		if(notVisibleLights.empty())
			cout << "All the lights are visible.\n";
		else {
			cout << "Some lights are not visible:\n";
			for(set<Pole>::iterator it = notVisibleLights.begin(); it != notVisibleLights.end();){
				cout << "x = " << (*it).x << ", y = " << (*it).y;
				if(++it != notVisibleLights.end()) cout << ";\n";
				else cout << ".\n";
			}
		}
		cin >> nPoles;
	}
	
	return 0;

}

Pole createPole(double x, double y, double z, double distance){
	Pole p;
	p.x = x;
	p.y = y;
	p.z = z;
	p.distance = distance;
	return p;
}

double distanceToTotem(double x, double y){
	return sqrt(x*x + y*y);
}