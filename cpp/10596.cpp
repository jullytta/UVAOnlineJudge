#include<iostream>
#include<vector>
#include<queue>

const int maxN = 201;

using namespace std;

const int white = 1;
const int gray = 2;
const int black = 3;

int color[maxN];
vector<int> roads[maxN];

void bfs(int root);

int main(void){

	bool possible;
	int n, r, a, b;
	int degree[maxN];
	
	while(cin >> n >> r){
		
		possible = true;
		
		if(r == 0)
			possible = false;
		
		for(int i = 0; i < n; i++){
			degree[i] = 0;
			color[i] = white;
			roads[i].clear();
		}
	
		for(int i = 0; i < r; i++){
			cin >> a >> b;
			degree[a]++;
			degree[b]++;
			roads[a].push_back(b);
			roads[b].push_back(a);
		}
		
		bfs(a);
		
		for(int i = 0; i < n; i++){
			if((degree[i])%2 == 1 || (color[i] == white && degree[i] != 0)){
				possible = false;
			}
		}
		
		if(possible)
			cout << "Possible\n";
		else
			cout << "Not Possible\n";
		
	}

	return 0;

}

void bfs(int root){

	int u, v;
	queue<int> q;
	
	q.push(root);

	color[root] = gray;
	
	while (!q.empty()){

		u = q.front();
		q.pop();

		for(vector<int>::iterator it = roads[u].begin(); it != roads[u].end(); it++){
			v = *it;
			if(color[v] == white){
				color[v] = gray;
				q.push(v);
			}
		}
		
		color[u] = black;
 
	}
	
}
