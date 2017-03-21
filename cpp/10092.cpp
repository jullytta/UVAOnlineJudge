#include<iostream>
#include<vector>
#include<queue>

const int maxInt = 1002;
const int maxN = 1500;
const int maxCategories = 22;

using namespace std;

int capacity[maxN][maxN];
int flow[maxN][maxN];
int pred[maxN];
vector<int> edges[maxN];
vector<int> chosenOnes[maxCategories];

void init(int n);
void clear(int n);
int EdmondsKarp(int n, int s, int t);

int main(void)
{
	bool possible;
	int n, s, t, temp, categoriesN, problemsN, pcN;
	
	cin >> categoriesN >> problemsN;

	while(categoriesN || problemsN)
	{

		n = problemsN + categoriesN + 2;
		s = problemsN+1;
		t = problemsN + categoriesN + 2;

		possible = true;

		init(n);

		for(int i = 0; i <= categoriesN; i++){
			chosenOnes[i].clear();
		}

/*
	Problemas são nós numerados de 1 a n.
	A fonte é n+1 e tem arestas de peso 1 para todos os problemas (só podemos usar cada problema uma vez).
	Tipos de problemas são numerados de n+2 a problemsN+n+1
	Cada problema é um nó, a aresta dele pros tipos dele tem peso 1
	cada tipo é um  nó também, e dele pro nó final o peso são quantos desse tipo a gente quer
	Se a aresta do problema para o tipo está saturada, o problema vai.
*/

		for(int i = 1; i <= problemsN; i++){
			edges[s].push_back(i);
			capacity[s][i] = 1;
			edges[i].push_back(s);
		}

		for(int i = problemsN+2; i <= problemsN+1+categoriesN; i++){
			cin >> temp;
			edges[i].push_back(t);
			capacity[i][t] = temp;
			edges[t].push_back(i);
		}

		for(int i = 1; i <= problemsN; i++){
			cin >> pcN;
			for(int j = 1; j <= pcN; j++){
				cin >> temp;
				temp += problemsN+1;
				edges[i].push_back(temp);
				capacity[i][temp] = 1;
				edges[temp].push_back(i);
			}
		}
		
		EdmondsKarp(n, s, t);

		for(int i = problemsN+2; i <= problemsN+1+categoriesN; i++){
			temp = 0;
			for(int j = 1; j <= problemsN; j++){
				if(flow[j][i]){
					chosenOnes[i-problemsN-1].push_back(j);
					temp++;
				}
			}
//			cout << "Temos " << temp << " problemas do tipo " << i-problemsN-1 << endl;
			if(temp != capacity[i][t])
				possible = false;
		}

		if(!possible)
			cout << 0 << endl;
		else {
			cout << 1 << endl;
			for(int i = 1; i <= categoriesN; i++){
				for(vector<int>::iterator it = chosenOnes[i].begin(); it != chosenOnes[i].end(); it++){
					cout << (*it);
					if(it != chosenOnes[i].end()) cout << " ";
				}
				cout << endl;
			}
		}

		cin >> categoriesN >> problemsN;
		
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