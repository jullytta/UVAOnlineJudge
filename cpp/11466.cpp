#include<iostream>
#include <cmath>

const int maxN = 10001000;

using namespace std;

void generatePrimes(bool *isPrime, int size);
bool prime (long long n);

int main(void){

	long long n, largestPrimeFactor;
	int primeFactors;
	bool *isPrime;

	isPrime = new bool[maxN];

	generatePrimes(isPrime, maxN);

	while(cin >> n && n){

		if(n < 0)
			n = n*(-1);
		
		if((n < 4) || (n < maxN && isPrime[n]) || prime(n)){
			cout << -1 << endl;
			continue;
		}

		primeFactors = 0;
		largestPrimeFactor = 1;

		if(n%2 == 0){
			primeFactors++;
			n = n/2;
			while(n%2 == 0)
				n = n/2;
		}

		for(int i = 3; i < maxN; i += 2){
			if(isPrime[i] && (n%i == 0)){
				largestPrimeFactor = i;
				n = n/i;
				while(n%i == 0)
					n = n/i;
				primeFactors++;
				if(prime(n)){
					primeFactors++;
					largestPrimeFactor = n;
					break;
				}
			}
		}

		if(primeFactors <= 1)
			largestPrimeFactor = -1;

		cout << largestPrimeFactor << endl;

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

bool prime (long long n){

	if(n < 2 || (n != 2 && n%2 == 0))
		return false;
	
	int length = sqrt(n*1.0);

	
	for(int i = 3; i <= length; i += 2){
		if(n%i == 0) return false;
	}

	return true;
}
