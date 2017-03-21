#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>

const int maxServers = 20001;
const int infinity = (1<<30);

using namespace std;

int heapSize;
int d[maxServers], position[maxServers], Heap[maxServers];
vector<int> edges[maxServers], edgeW[maxServers];
bool Free[maxServers];

void dijkstra(int root, int goal);
void UpdateHeap(int v);
int PopHeap();

int main(void){

	bool reachable;
	int testCases, requiredTime, from, to, nServers, nCables, a, b, w;

	cin >> testCases;

	for(int i = 1; i <= testCases; i++){

		reachable = false;
		requiredTime = 0;

		cin >> nServers >> nCables >> from >> to;

		for(int j = 0; j < nServers; j++){
			edges[j].clear();
			edgeW[j].clear();
			d[j] = infinity;
			position[j] = 0;
			Free[j] = true;
		}

		for(int j = 0; j < nCables; j++){
			cin >> a >> b >> w;
			edges[a].push_back(b);
			edgeW[a].push_back(w);
			edges[b].push_back(a);
			edgeW[b].push_back(w);
		}

		dijkstra(from, to);

		requiredTime = d[to];

		if(requiredTime != infinity) reachable = true;

		cout << "Case #" << i << ": ";
		if(reachable)
			cout << requiredTime << endl;
		else
			cout << "unreachable" << endl;

	}

	return 0;

}

void dijkstra(int root, int goal){

	int u, v;

	d[root] = 0;
	heapSize = 0;

	UpdateHeap(root);

	do {
		u = PopHeap();
		if(u == goal) break;

		Free[u] = false;
		for(int i = 0; i < int (edges[u].size()); i++){
			v = edges[u][i];
			if(Free[v] && d[u]+edgeW[u][i] < d[v]){
				d[v] = d[u]+edgeW[u][i];
				UpdateHeap(v);
			}
		}
	
	} while(heapSize != 0);

}

void UpdateHeap(int v) {
    int child = position[v];
    if (child==0) child = ++heapSize;
    int parent = child/2;
    while (parent>0 && d[Heap[parent]]>d[v]) {
        Heap[child] = Heap[parent];
        position[Heap[child]] = child;
        child = parent;
        parent = child/2;
    }
    Heap[child] = v;
    position[v] = child;
}

int PopHeap() {
    int pop = Heap[1];
    int v = Heap[heapSize--], r = 1;
    while (r+r<=heapSize) {
        int c= r+r;
        if (c<heapSize && d[Heap[c+1]]<d[Heap[c]]) c++;
        if (d[v]<=d[Heap[c]]) break;
        Heap[r] = Heap[c];
        position[Heap[r]] = r;
        r = c;
    }
    Heap[r] = v;
    position[v] = r;
    return pop;
}
