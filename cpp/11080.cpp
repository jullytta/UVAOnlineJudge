#include<iostream>
#include<vector>
#include<set>
#include<queue>

const int maxV = 201;
const int maxE = 10001;

using namespace std;

#define WHITE 1
#define RED 2
#define BLUE 3

vector<int> color(maxV, WHITE);

int bfs(int key, set<int> *edges);

int main (void){

	bool impossible;
	int testCases, v, e, a, b, result;
	set<int> *edges;

	cin >> testCases;

	for(int i = 0; i < testCases; i++){

		cin >> v >> e;

		edges = new set<int>[v];

		impossible = false;
		result = 0;

		for(int j = 0; j < v; j++)
			color[j] = WHITE;

		for(int j = 0; j < e; j++){
			cin >> a >> b;
			edges[a].insert(b);
			edges[b].insert(a);
		}

		for(int j = 0; j < v && !impossible; j++){

			if(color[j] == WHITE){
				a = bfs(j, edges);
				if(a == -1)
					impossible = true;
				else
					result += a;
			}
		}

		if(impossible)
			result = -1;

		cout << result << endl;

	}

	return 0;

}

int bfs(int key, set<int> *edges){

	int reds, seen, node, adj;
	queue<int> q;
	q.push(key);

	color[key] = RED;

	reds = seen = 0;
 
	while (!q.empty()){

		node = q.front();
		q.pop();
		seen++;

		if(color[node] == RED) reds++;

		for(set<int>::iterator it = edges[node].begin(); it != edges[node].end(); it++){
			adj = *it;
			if(color[adj] == WHITE){
				if(color[node] == RED)
					color[adj] = BLUE;
				else color[adj] = RED;
				q.push(adj);
			} else if(color[adj] == color[node]) return -1;
		}
 
	}

	if (seen == 1) return 1;

	return min(reds,seen-reds);

}
