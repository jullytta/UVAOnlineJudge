#include<iostream>

const int maxN = 30000;
const int maxM = 500000;

using namespace std;

int set[maxN];
int size[maxN];

void unionFind(int a, int b);
int find(int key);

int main(void){

	int testCases, n, m, a, b, max;
	
	cin >> testCases;
	
	for(int i = 0; i < testCases; i++){
		
		max = 0;

		cin >> n >> m;

		for(int j = 0; j < n; j++){
			set[j] = j;
			size[j] = 1;
		}
		
		for(int j = 0; j < m; j++){
			cin >> a >> b;
			unionFind(a-1, b-1);			
		}

		for(int j = 0; j < n; j++){
			if(size[j] > max)
				max = size[j];
		}
		
		cout << max << endl;

	}

	return 0;

}

void unionFind(int a, int b){

	int c, d;

	c = find(a);
	d = find(b);

	if(c != d){
		if(size[c] < size[d]){
			set[c] = d;
			size[d] += size[c];
		}
		else {
			set[d] = c;
			size[c] += size[d];
		}
	}

}


int find(int key){

	int swp, result, it;

	it = result = key;

	while(result != set[result])
		result = set[result];

	//Compressao de caminhos:
	while(set[it] != result){
		swp = set[it];
		set[it] = result;
		it = swp;
	}

	return result;

}
