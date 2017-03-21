#include<iostream>
#include<map>
#include<vector>
#include<queue>

#define ASSERTION '!'
#define QUERY '?'
#define BREAK '.'
#define WHITE 0
#define GRAY 1
#define BLACK 2

using namespace std;

struct exchangeRate {
	int ratioA;
	int ratioB;
};

const int maxItens = 100;
vector<int> color(maxItens, WHITE);
vector<int> edges[maxItens];
exchangeRate rates[maxItens][maxItens];
map<string, int> index;

int gdc(int a, int b);
bool bfsSearch(int itemA, int itemB);


int main (void){
	
	char action;
	bool found;
	int ratioA, ratioB, nextIndex, divisor;
	string itemA, itemB;

	action = ' ';
	nextIndex = 0;

	for(int i = 0; i < maxItens; i++){
		for(int j = 0; j < maxItens; j++){
			rates[i][j].ratioA = rates[i][j].ratioB = -1;
		}
	}

	while(cin >> action && action != BREAK){
		
		switch(action){
			case ASSERTION:
				cin >> ratioA >> itemA >> action >> ratioB >> itemB;
				if(index.find(itemA) == index.end())
					index.insert(pair<string,int>(itemA, nextIndex++));
				if(index.find(itemB) == index.end())
					index.insert(pair<string,int>(itemB, nextIndex++));
			
				divisor = gdc(ratioA, ratioB);
				ratioA /= divisor;
				ratioB /= divisor;

				edges[index[itemA]].push_back(index[itemB]);
				edges[index[itemB]].push_back(index[itemA]);

				rates[index[itemA]][index[itemB]].ratioA = ratioA;
				rates[index[itemA]][index[itemB]].ratioB = ratioB;
				rates[index[itemB]][index[itemA]].ratioA = ratioB;
				rates[index[itemB]][index[itemA]].ratioB = ratioA;
				
				break;
				
			case QUERY:
				cin >> itemA >> action >> itemB;
				if(rates[index[itemA]][index[itemB]].ratioA != -1)
					found = true;
				
				if(!found){
					for(int i = 0; i < (int) index.size(); i++)	color[i] = WHITE;
					found = bfsSearch(index[itemA], index[itemB]);
				}

				if(found){
					found = false;
					ratioA = rates[index[itemA]][index[itemB]].ratioA;
					ratioB = rates[index[itemA]][index[itemB]].ratioB;
					cout << ratioA << " " << itemA << " = " << ratioB << " " << itemB << endl;
				} else {				
					cout << "? " << itemA << " = " << "? " << itemB << endl;
				}
				
				break;
		}

	}
	
	return 0;

}

int gdc(int a, int b){
		if(a%b == 0)
			return b;
		else return gdc(b, a%b);
}

bool bfsSearch(int itemA, int itemB){

	int node, adj, rA, rB, d;
	queue<int> q;
	node = itemA;
	q.push(node);

	color[node] = GRAY;
 
	while (!q.empty()){

		node = q.front();
		q.pop();

		for(vector<int>::iterator it = edges[node].begin(); it != edges[node].end(); it++){
			adj = *it;

			if(color[adj] == WHITE){
				color[adj] = GRAY;
				if(rates[itemA][adj].ratioA == -1){
					rA = rates[itemA][node].ratioA * rates[node][adj].ratioA;
					rB = rates[itemA][node].ratioB * rates[node][adj].ratioB;
					d = gdc(rA, rB);
					rA /= d;
					rB /= d;
					rates[itemA][adj].ratioA = rA;
					rates[itemA][adj].ratioB = rB;
					rates[adj][itemA].ratioA = rB;
					rates[adj][itemA].ratioB = rA;
					if(adj == itemB)
						return true;
				}
				q.push(adj);
			}

		}

		color[node] = BLACK;
 
	}

	return false;

}
