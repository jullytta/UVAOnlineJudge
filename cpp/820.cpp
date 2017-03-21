#include<iostream>
#include<vector>
#include<queue>

const int maxBandwidth = 1002;
const int maxN = 102;

using namespace std;

int capacity[maxN][maxN];
int flow[maxN][maxN];
int pred[maxN];
vector<int> edges[maxN];

void init(int n);
void clear(int n);
int EdmondsKarp(int n, int s, int t);

int main(void)
{
	
	int n, s, t, c, x, y, band, caseNum, maxFlow;
	
	cin >> n;
	caseNum = 0;

	while(n)
	{
		init(n);
		caseNum++;

		cin >> s >> t >> c;

		for(int i = 0; i < c; i++)
		{
			cin >> x >> y >> band;
			capacity[x][y] += band;
			capacity[y][x] += band;
			edges[x].push_back(y);
			edges[y].push_back(x);
		}
		
		maxFlow = EdmondsKarp(n, s, t);

		cout << "Network " << caseNum << "\nThe bandwidth is " << maxFlow << ".\n\n";

		cin >> n;
		
	}
	
	return 0;
	
}

void init(int n){
	for(int i = 0; i <= n; i++){
		edges[i].clear();
		pred[i] = 0;
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

		flowAdd = maxBandwidth;
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
			v = u;
			u = pred[v];
		}

		maxFlow += flowAdd;

		clear(n);

	}

	return maxFlow;
}