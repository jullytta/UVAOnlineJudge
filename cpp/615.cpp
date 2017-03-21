#include<iostream>
#include<cmath>
#include<map>
#include<vector>

const int maxN = 1001;

#define WHITE 1
#define GRAY 2
#define BLACK 3

using namespace std;

vector<int> color(maxN, WHITE);
int findRoot(map<int,int> degrees);
void dfs(int root, map<int, int> node, vector< vector<int> > edges);
bool isItATree(int size);

int main (void){
	
	int a, b, k, root, nextNode;
	bool tree;
	map<int, int> degrees;
	map<int, int> node;	
	vector< vector<int> > edges(maxN, vector<int>());
	
	k = 0;
	tree = false;
	
	cin >> a >> b;
	
	while(a != -1 && b != -1){

		k++;
		root = -1;
		nextNode = 0;
		
		if(a == 0 && b == 0){
			cout << "Case " << k << " is a tree.\n";
			cin >> a >> b;
			continue;
		}

		while(a != 0 && b != 0){
			
			degrees.insert(pair<int,int> (a, 0));

			if(node.find(a) == node.end())
				node.insert(pair<int,int> (a, nextNode++));

			if(node.find(b) == node.end())
				node.insert(pair<int,int> (b, nextNode++));

			degrees[b]++;
			edges[node[a]].push_back(b);
			
			cin >> a >> b;

		}

		root = findRoot(degrees);

		if(root == -1){
			tree = false;
		} else{
//			cout << "We have our root, it's " << root << "! Time to find out if we've got a tree!\n";
			dfs(root, node, edges);
			tree = isItATree(nextNode);
		}
		
		if(tree)
			cout << "Case " << k << " is a tree.\n";
		else
			cout << "Case " << k << " is not a tree.\n";

		degrees.clear();
		node.clear();

		for(int i = 0; i < nextNode; i++){
			edges[i].clear();
			color[i] = WHITE;
		}

		cin >> a >> b;
		
	}

	return 0;

}

int findRoot(map<int,int> degrees){

	int node, nodeDegree, root;
	map<int, int>::iterator it;

	root = -1;

	for (it = degrees.begin(); it != degrees.end(); it++){
		node = it->first;
		nodeDegree = it->second;

		if(nodeDegree > 1)
			return -1;

		if(nodeDegree == 0){
			if(root == -1)
				root = node;
			else
				return -1;
		}
	}

	return root;

}

void dfs(int root, map<int, int> node, vector< vector<int> > edges){

	int visited = node[root];
	int son;

	color[visited] = GRAY;

	for(vector<int>::iterator it = edges[visited].begin(); it != edges[visited].end(); ++it) {
		son = *it;
//		cout << son << " é filho de " << root << endl;
		if(color[(node[son])] == WHITE){
			dfs(son, node, edges);
		}
	}

	color[visited] = BLACK;

}

bool isItATree(int size){

	for(int i = 0; i < size; i++){
		if(color[i] == WHITE){
//			cout << "Oh nos! " << i << " is WHITE!\n";
			return false;
		}
	}

	return true;

}
