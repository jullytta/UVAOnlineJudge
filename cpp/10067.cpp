#include<iostream>
#include<map>
#include<vector>
#include<queue>

using namespace std;

const int vectorSize = 4;
const int maxStates = 10010;

int counter[maxStates];
bool visited[maxStates];

int bfs(vector<int> inicial, vector<int> destination);
int makeNum(vector<int> &v);

int main (void){

	int testCases, swp, nForbidden;
	vector<int> inicial, destination, forbidden;

	cin >> testCases;

	for(int n = 0; n < testCases; n++){

		for(int i = 0; i < maxStates; i++){
			visited[i] = false;
		}

		for(int i = 0; i < vectorSize; i++){
			cin >> swp;
			inicial.push_back(swp);
		}

		for(int i = 0; i < vectorSize; i++){
			cin >> swp;
			destination.push_back(swp);
		}

		cin >> nForbidden;

		for(int j = 0; j < nForbidden; j++){
			forbidden.clear();
			for(int i = 0; i < vectorSize; i++){
				cin >> swp;
				forbidden.push_back(swp);
			}
			visited[makeNum(forbidden)] = true;
		}
		
		cout << bfs(inicial, destination) << endl;

		inicial.clear();
		destination.clear();

	}

	return 0;

}

int bfs(vector<int> inicial, vector<int> destination){

	queue< vector<int> > q;
	vector<int> v, child;

	counter[makeNum(inicial)] = 0;
	q.push(inicial);

	while(!q.empty()){
		v.clear();
		v = q.front();
		q.pop();
		
		if(visited[makeNum(v)] == true) continue;

		visited[makeNum(v)] = true;

		if(v == destination) return counter[makeNum(v)];

		child = v;

		for(int i = 0; i < vectorSize; i++){
			child[i] += 1;
			child[i] %= 10;
			if(visited[makeNum(child)] == false)
				q.push(child);
			counter[makeNum(child)] = counter[makeNum(v)]+1;
			child = v;
		}

		for(int i = 0; i < vectorSize; i++){
			child[i] -= 1;
			if(child[i] == -1) child[i] = 9;
			if(visited[makeNum(child)] == false)
				q.push(child);
			counter[makeNum(child)] = counter[makeNum(v)]+1;
			child = v;
		}

	}

	return -1;

}

int makeNum(vector<int> &v){

	int result;

	result = 0;
	result += v[0] * 1000;
	result += v[1] * 100;
	result += v[2] * 10;
	result += v[3];

	return result;

}
