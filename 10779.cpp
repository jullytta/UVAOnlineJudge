/*
	Accepted code for 10779 - Collectors Problem
	Language: C++
	Runtime: 0.012
	Author: Jullytta
	Submitted: 2015-06-14 19:40:25
*/

#include<iostream>
#include<vector>
#include<queue>

const int maxN = 100;
const int maxK = 30;

using namespace std;

int capacity[maxN][maxN];
int flow[maxN][maxN];
int pred[maxN];
int count[maxK];
vector<int> edges[maxN];

void init(int n);
void clear(int n);
void refreshCounter(int k);
int EdmondsKarp(int n, int s, int t);

int main(void)
{
	
	int n, k, s = 1, t, stickers, testCases, maxFlow, temp, numNodes;
	
	cin >> testCases;

/*
	We have a maximum flow problem. Here's how I modeled it:
		- Bob is node number 1 and his friends are numbered from 2 to n.
		- Stickers are numbered from n+1 to n+k, we have k different stickers.
		- Our sink is therefore n+k+1. The source is Bob.
		- From each sticker we've got an edge to sink with capacity 1.
		- From Bob, there's an edge to each sticker he has,
		capacity being the number of stickers of this type he has.
		- His friends are not that clever, so for each one of them
		there's an edge to each sticker they have, but the capacity is
		m-1 where m is the number of stickers of this type they have.
		- If a friend doesn't have a sticker, them we add a edge from this
		friend to this sticker with capacity 1.

*/

	for(int caseNum = 1; caseNum <= testCases; caseNum++)
	{

		cin >> n >> k;
		numNodes = n+k+1;
		t = n+k+1;

		init(numNodes);

		// Bob
		refreshCounter(k);
		cin >> stickers;
		for(int i = 0; i < stickers; i++){
			cin >> temp;
			count[temp]++;
		}
		for(int i = 1; i <= k; i++){
			if(count[i] != 0){
				edges[1].push_back(i+n);
				capacity[1][i+n] = count[i];

				edges[i+n].push_back(1);
			}
		}

		// For each friend i
		for(int i = 2; i <= n; i++){
			refreshCounter(k);
			cin >> stickers;
			for(int j = 0; j < stickers; j++){
				cin >> temp;
				count[temp]++;
			}
			for(int j = 1; j <= k; j++){
				if(count[j] == 0){
					edges[j+n].push_back(i);
					capacity[j+n][i] = 1;

					edges[i].push_back(j+n);
				}
				edges[i].push_back(j+n);
				capacity[i][j+n] = count[j]-1;

				edges[j+n].push_back(i);
			}
		}

		// Sink
		for(int i = n+1; i <= n+k; i++){
			edges[i].push_back(t);
			capacity[i][t] = 1;

			edges[t].push_back(i);
		}

		maxFlow = EdmondsKarp(numNodes, s, t);

		cout << "Case #" << caseNum << ": " << maxFlow << endl;
		
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

void refreshCounter(int k){
	for(int i = 1; i <= k; i++)
		count[i] = 0;
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

		flowAdd = maxK;
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