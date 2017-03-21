#include<iostream>
#include<vector>
#include<string>
#include<sstream>
#include<climits>
#include<iomanip>

using namespace std;

const int maxK = 101;

vector< pair<int, int> > prices;
int bestPrice[maxK];

int main (void){

	char dot;
	int price, cents, tags, itens, temp, caseNum;
	string buffer;

	caseNum = 1;

	while(cin >> price >> dot >> cents >> tags){

		prices.push_back(pair<int,int>(1, price*100+cents));

		for(int i = 0; i < tags; i++){
			cin >> itens >> price >> dot >> cents;
			prices.push_back(pair<int,int>(itens, price*100+cents));
		}

		bestPrice[0] = 0;
		for(int i = 1; i < maxK; i++){
			bestPrice[i] = INT_MAX;
			for(vector< pair<int,int> >::iterator it = prices.begin(); it != prices.end(); it++){
				itens = (*it).first;
				price = (*it).second;
				if(i-itens > 0) temp = i-itens;
				else temp = 0;
				if(bestPrice[i] > bestPrice[temp]+price)
					bestPrice[i] = bestPrice[temp]+price;
			}
		}

		getline(cin, buffer);
		getline(cin, buffer);
		stringstream ss(buffer);

		cout << "Case " << caseNum << ":\n";
		while(ss >> temp){
			cout << "Buy " << temp << " for $" << bestPrice[temp] / 100 << "." << setw(2)
					<< setfill('0') << bestPrice[temp] % 100 << endl;
		}

		caseNum++;
		prices.clear();

	}

	return 0;

}