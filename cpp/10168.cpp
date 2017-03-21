#include<iostream>
#include <cmath>

const int maxN = 10000000;

using namespace std;

void generatePrimes(bool *isPrime, int size);
void complete(int n, bool *isPrime);

int main(void){

	int n;
	bool *isPrime;

	isPrime = new bool[maxN];

	generatePrimes(isPrime, maxN);

	while(cin >> n){
		
		if(n < 8)
			cout << "Impossible.\n";
		else {
			if(n%2){
				cout << "2 3 ";
				complete(n - 5, isPrime);
			}
			else {
				cout << "2 2 ";
				complete(n - 4, isPrime);
			}
			cout << "\n";
		}

	}

	return 0;

}

void generatePrimes(bool *isPrime, int size){

	for(int i = 0; i < size; i++)
		isPrime[i] = true;

	isPrime[0] = isPrime[1] = false;

	for (int i = 4; i < size; i += 2)
		isPrime[i] = false;

	for(int i = 3; i*i <= size; i += 2){
		if(isPrime[i]){
			for(int j = i*i; j < size; j += 2*i)
				isPrime[j] = false;
		}
	}

}

void complete(int n, bool *isPrime){

	if(isPrime[n-2]){
		cout << "2 " << n-2;
	}
	else {
		for(int i = 3; i < maxN; i += 2){
			if(isPrime[n-i] && isPrime[i]){
				cout << i << " " << n-i;
				break;
			}
		}
	}

}
