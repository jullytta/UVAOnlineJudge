#include <iostream>
#include <cmath>

using namespace std;

int main(){

	double numDigits;
	long long n, k;

	while(cin >> n >> k){
		
		numDigits = 0;
		
		if(k > n-k){
			for(long long i = k+1; i <= n; i++)
				numDigits += (log10(i) - log10(n-i+1));
		}
		else {
			for(long long i = n-k+1; i <= n; i++)
				numDigits += (log10(i) - log10(n-i+1));
		}

		numDigits = floor (numDigits) + 1;

		cout << numDigits << endl;

	}

	return 0;

}
