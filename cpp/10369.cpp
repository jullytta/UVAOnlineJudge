#include<iostream>
#include<cmath>
#include<vector>
#include<algorithm>
#include<stdio.h>

const int maxSatellites = 101;
const int maxOutposts = 501;
const int maxCombinations = 124751;

using namespace std;

struct Connection{
	int a, b;
	double d;
};

int set[maxOutposts];
int size[maxOutposts];

void unionFind(int a, int b);
int find(int key);

bool comparisonConnection(Connection a, Connection b);

int main(void){
	
	int testCases, nSatellites, nOutposts, edgesPut;
	int x[maxOutposts], y[maxOutposts];
	double result;
	Connection swp;
	vector<Connection> connections;
	vector<Connection>::iterator it;
	
	cin >> testCases;
	
	for(int i = 0; i < testCases; i++){
		
		cin >> nSatellites >> nOutposts;
		result = 0;
		edgesPut = 0;
		
		for(int j = 0; j < nOutposts; j++){
			cin >> x[j] >> y[j];
			set[j] = j;
			size[j] = 1;
		}
		
		for(int j = 0; j < nOutposts; j++){
			for(int k = j; k < nOutposts; k++){
				if(k != j){
					swp.d = sqrt(((x[j] - x[k])*(x[j] - x[k]))+ ((y[j] - y[k])*(y[j] - y[k])));
					swp.a = j;
					swp.b = k;
					connections.push_back(swp);
				}
			}
		}
		
		sort(connections.begin(), connections.end(), comparisonConnection);

		for(it = connections.begin(); (edgesPut < nOutposts-nSatellites) && it != connections.end(); it++){
			if(find((*it).a) != find((*it).b)){
				unionFind((*it).a, (*it).b);
				edgesPut++;
			}
		}
		it--;
		result = (*it).d;

		printf("%.2f\n", result);
		
		connections.clear();
		
	}
	
	return 0;
	
}

bool comparisonConnection(Connection a, Connection b){
	return a.d < b.d;
}

void unionFind(int a, int b){

	int c, d;

	c = find(a);
	d = find(b);

	if(c != d){
		if(size[c] < size[d]){
			set[c] = d;
			size[d] += size[c];
		}
		else {
			set[d] = c;
			size[c] += size[d];
		}
	}

}


int find(int key){

	int swp, result, it;

	it = result = key;

	while(result != set[result])
		result = set[result];

	while(set[it] != result){
		swp = set[it];
		set[it] = result;
		it = swp;
	}

	return result;

}
