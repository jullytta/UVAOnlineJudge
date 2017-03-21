#include<iostream>
#include<vector>

const int maxM = 201;
const int maxC = 21;
const int notKnown = -2;
const int notPossible = -1;

using namespace std;

int maxSpend[maxM][maxC];
vector<int> prices[maxC];

int buy(int M, int C);

int main (void){

	int testCases, M, C, K, temp, result;

	cin >> testCases;

	while(testCases--){
		cin >> M >> C;
		for(int i = 0; i <= M; i++){
			for(int j = 0; j <= C; j++)
				maxSpend[i][j] = notKnown;
		}
		for(int i = 0; i < C; i++){
			cin >> K;
			prices[i].clear();
			for(int j = 0; j < K; j++){
				cin >> temp;
				prices[i].push_back(temp);
			}
		}
		result = buy(M, C);
		if(result == notPossible)
			cout << "no solution\n";
		else
			cout << result << endl;
	}

	return 0;

}

int buy(int M, int C){
	int result;
	if(M < 0) return notPossible;
	if(C == 0){
		maxSpend[M][C] = 0;
		return 0;
	}
	if(maxSpend[M][C] != notKnown){
		return maxSpend[M][C];
	}

	result = notPossible;
	for(vector<int>::iterator it = prices[C-1].begin(); it != prices[C-1].end(); it++){
		if(buy(M - *it, C-1) != notPossible){
			if(maxSpend[M-*it][C-1]+*it > result){
				result = maxSpend[M-*it][C-1] + *it;
			}
		}
	}
	maxSpend[M][C] = result;
	return result;

}