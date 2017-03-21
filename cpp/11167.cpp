#include<iostream>
#include<vector>
#include<queue>

const int maxInt = 1002;
const int maxN = 10000;

using namespace std;

int capacity[maxN][maxN];
int flow[maxN][maxN];
int pred[maxN];
vector<int> edges[maxN];

void printDrinks(int n);
void init(int n);
void clear(int n);
int EdmondsKarp(int n, int s, int t);

struct timeStamp
{
	int begin;
	int end;
};

vector<timeStamp> drinkingTime[maxN];

int main(void)
{
	bool canDrink;
	int n, mTogether, s, t, drink, time1, time2, maxTime, caseNum;
	
	cin >> n;
	caseNum = 0;

	while(n)
	{
		init(maxN);
		caseNum++;
		maxTime = 0;
		canDrink = true;

/*
	A fonte é s = n+1.
	Temos n macacos numerados de 1 a n. maxTime tempos numerados de n+1+1 até n+maxTime+1.
	O sumidouro é t = n+maxTime+1+1.
	Da fonte para cada macaco temos uma aresta com capacidade o quanto ele quer beber.
	Do macaco para cada tempo no qual ele pode beber temos uma aresta de capacidade 1.
	De cada tempo para o sumidouro temos uma aresta com capacidade quantos macacos podem beber por vez.
	O macaco bebeu nos temos nos quais existe fluxo do macaco para o tempo.
	Verificar se ele bebeu tudo que tinha de beber, caso não responder No.
*/

		cin >> mTogether;
		s = n+1;

		for(int i = 1; i <= n; i++)
		{
			cin >> drink >> time1 >> time2;
			maxTime = max(time2, maxTime);

			edges[s].push_back(i);
			capacity[s][i] = drink;
			edges[i].push_back(s);

			for(int j = time1+n+2; j <= time2+n+1; j++){
				edges[i].push_back(j);
				capacity[i][j] = 1;
				edges[j].push_back(i);
			}

		}

		t = maxTime+n+1+1;

		for(int i = n+1+1; i <= n+maxTime+1; i++){
			edges[i].push_back(t);
			capacity[i][t] = mTogether;
			edges[t].push_back(i);
		}

		EdmondsKarp(n+t, s, t);

		timeStamp swp;
		int t;
		for(int i = 1; i <= n; i++){
			drink = capacity[s][i];
			t = n+2;
			while(drink){
				if(flow[i][t]){
					swp.begin = t-n-2;
					drink--;
					while(flow[i][++t]) drink--;
					swp.end = t-n-2;
					drinkingTime[i].push_back(swp);
				}
				t++;
				if(t > maxTime+n+2 && drink != 0){ canDrink = false; break; }
			}
		}

		cout << "Case " << caseNum << ": ";
		if(canDrink){
			cout << "Yes\n";
			printDrinks(n);
		}
		else cout << "No\n";

		cin >> n;
		
	}
	
	return 0;
	
}

void printDrinks(int n){
	for(int monkey = 1; monkey <= n; monkey++){
		cout << drinkingTime[monkey].size() << " ";
		for(vector< timeStamp >::iterator it = drinkingTime[monkey].begin(); it != drinkingTime[monkey].end(); it++){
			cout << "(" << (*it).begin << "," << (*it).end << ")";
			if (it != drinkingTime[monkey].end()) cout << " ";
		}
		cout << endl;
	}
}

void init(int n){
	for(int i = 0; i <= n; i++){
		edges[i].clear();
		drinkingTime[i].clear();
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

	while(true){

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