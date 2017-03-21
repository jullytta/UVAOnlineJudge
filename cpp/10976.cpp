#include<iostream>

using namespace std;

int main (void){
	
	int k, x, y, pairs;
	
	while(cin >> k){
	
		pairs = 0;

		for(y = k+1; y <= 2*k; y++){
				if(((k*y)%(y-k)) == 0)
					pairs++;
		}
		
		cout << pairs << endl;
		
		for(y = k+1; y <= 2*k; y++){
			if(((k*y)%(y-k)) == 0){
				x = (k*y)/(y-k);
				cout << "1/" << k << " = 1/" << x << " + 1/" << y << endl;
			}
		}
		
	}

	return 0;
	
}
