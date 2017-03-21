/*
	Code for 10480 - Sabotage
	Language: C++
	Runtime: ?
	Author: Jullytta
	Submitted: ?
*/

/*
	This one is about minimum cut.
	The capital is our source, city number 1.
	The largest city is the sink, city number 2.
*/

#include <iostream>
#include <vector>
#include <queue>
#include <stack>

const int maxInt = 1002;
const int maxN = 100;
const int WHITE = 0;
const int GRAY = 1;
const int BLACK = 2;

using namespace std;

int capacity[maxN][maxN];
int flow[maxN][maxN];
int pred[maxN];
int color[maxN];
vector<int> edges[maxN];

void init(int n);
void clear(int n);
int EdmondsKarp(int n, int s, int t);
void findCut(int s);

int main(void)
{
	
	int n, m, s, t, x, y, c;
	
	cin >> n >> m;

	while(n != 0 && m != 0)
	{

		init(n);

		s = 1;
		t = 2;

		for(int i = 0; i < m; i++)
		{
			cin >> x >> y >> c;
			capacity[x][y] += c;
			edges[x].push_back(y);
			edges[y].push_back(x);
			capacity[y][x] += c;
		}
		
		EdmondsKarp(n, s, t);

		findCut(s);

		cout << endl;
		
		cin >> n >> m;

	}
	
	return 0;
	
}

void init(int n){
	for(int i = 0; i <= n; i++){
		edges[i].clear();
		pred[i] = 0;
		color[i] = WHITE;
		for(int j = 0; j <= n; j++){
			capacity[i][j] = 0;
			flow[i][j] = 0;
		}
	}
}

void clear(int n){
	for(int i = 0; i <= n; i++)
		pred[i] = 0;
}

int EdmondsKarp(int n, int s, int t){
	int maxFlow = 0, u, v, flowAdd;

	queue<int> q;

	int k = 2;
	while(k){

		q.push(s);
		while(!q.empty()){
			u = q.front();
			q.pop();
			for(vector<int>::iterator it = edges[u].begin(); it != edges[u].end(); it++){
				v = *it;
				if(pred[v] == 0 && v != s && capacity[u][v] > flow[u][v]){
					pred[v] = u;
					q.push(v);
				}
			}
		}

		if(pred[t] == 0)
			break;

		flowAdd = maxInt;
		v = t;
		u = pred[t];
		while(u != 0){
			flowAdd = min(flowAdd, capacity[u][v] - flow[u][v]);
			v = u;
			u = pred[v];
		}

		v = t;
		u = pred[t];

		while(u != 0){
			flow[u][v] += flowAdd;
			flow[v][u] -= flowAdd;
			v = u;
			u = pred[v];
		}

		maxFlow += flowAdd;

		clear(n);

	}

	return maxFlow;

}

void findCut(int s){

	stack<int> st;

	st.push(s);

	int u, v;
	while(!st.empty()){
		u = st.top();
		st.pop();
		if(color[u] == WHITE){
			color[u] = GRAY;
			for(vector<int>::iterator it = edges[u].begin(); it != edges[u].end(); it++){
				v = *it;
				if(flow[u][v] == capacity[u][v]){
					cout << u << " " << v << endl;
				}
				else st.push(v);
			}
		}
	}

}