#include<iostream>
#include <cmath>

const int maxN = 65000;

using namespace std;

void generatePrimes(bool *isPrime, int size);
bool isCarmichael(bool *isPrime, long long n);
int modPow(long long base, int exp, int mod);

int main(void){

	long long n;
	bool *isPrime;

	isPrime = new bool[maxN];

	generatePrimes(isPrime, maxN);

	while(cin >> n && n){
		if(isCarmichael(isPrime, n))
			cout << "The number " << n << " is a Carmichael number." << endl;
		else
			cout << n << " is normal." << endl;
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

bool isCarmichael(bool *isPrime, long long n){

	if(isPrime[n])
		return false;
	else {
		for(long long a = 2; a < n; a++){
			if(a != modPow(a, n, n)){
				return false;
			}
		}
	}

	return true;

}

int modPow(long long base, int exp, int mod){

	long long result = 1;

	while(exp != 0){
		if(exp%2)
			result = (result*base)%mod;
		exp /= 2;
		base = (base*base)%mod;
	}

	return result;

}
