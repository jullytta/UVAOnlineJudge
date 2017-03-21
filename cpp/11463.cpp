#include<iostream>
#include<vector>
#include<queue>

using namespace std;

const int maxBuildings = 101;
const int white = 1;
const int gray = 2;
const int black = 3;

int minTime;
int color[maxBuildings];
vector<int> roads[maxBuildings];

void bfs(int root, int *timeTable);

int main(void){
	
	int testCases, nBuildings, nRoads, start, meet, a, b, swp;
	int timeGoing[maxBuildings];
	int timeComing[maxBuildings];
	
	cin >> testCases;
	
	for(int i = 0; i < testCases; i++){
		
		minTime = 0;
			
		cin >> nBuildings >> nRoads;
		
		for(int j = 0; j < nBuildings; j++){
			color[j] = white;
			roads[j].clear();
		}
		
		for(int j = 0; j < nRoads; j++){
			
			cin >> a >> b;
			
			roads[a].push_back(b);
			roads[b].push_back(a);
			
		}
		
		cin >> start >> meet;
		
		bfs(start, timeGoing);
		
		for(int j = 0; j < nBuildings; j++)
			color[j] = white;
		
		bfs(meet, timeComing);

		for(int j = 0; j < nBuildings; j++){
			swp = timeComing[j] + timeGoing[j];
			if(minTime < swp)
				minTime = swp;
		}
		
		cout << "Case " << i+1 << ": " << minTime << endl;
		
	}
	
	return 0;
	
}

void bfs(int root, int *timeTable){

	int u, v;
	queue<int> q;
	
	q.push(root);

	timeTable[root] = 0;

	color[root] = gray;
	
	while (!q.empty()){

		u = q.front();
		q.pop();

		for(vector<int>::iterator it = roads[u].begin(); it != roads[u].end(); it++){
			v = *it;
			if(color[v] == white){
				color[v] = gray;
				timeTable[v] = timeTable[u]+1;
				q.push(v);
			}
		}
		
		color[u] = black;
 
	}
	
}
