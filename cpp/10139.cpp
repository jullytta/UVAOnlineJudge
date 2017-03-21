#include<iostream>
#include<cmath>
#include<map>

const int maxN = 46350;

using namespace std;

void generatePrimes(bool *isPrime, int size);
bool doesDivide(int n, int m, bool *isPrime);
int getPowers(long long n, int p);
bool prime (long long n, bool *isPrime);

int main(void){

	int n, m;
	bool *isPrime;

	isPrime = new bool[maxN];

	generatePrimes(isPrime, maxN);

	while(cin >> n >> m){

		if(doesDivide(n,m, isPrime))
			cout << m << " divides " << n << "!\n";
		else
			cout << m << " does not divide " << n << "!\n";

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

bool doesDivide(int n, int m, bool *isPrime){

	int count, factor, i;
	map<int, int> factors;
	map<int, int>::iterator it;

	if(m == 0)
		return false;

	if(n <= 1){
		if(m == 1)
			return true;
		else
			return false;
	}

	if(m <= n)
		return true;

	while(m%2 == 0){
		factors[2]++;
		m /= 2;
	}

	if(prime(m, isPrime))
		factors[m]++;
	else {
		for(int i = 3; i < maxN; i += 2){
			if(isPrime[i]){
				while(m%i == 0){
					factors[i]++;
					m /= i;
				}
				if(prime(m, isPrime)){
					factors[m]++;
					break;
				}
				if(m == 1)
					break;
			}
		}
	}

	for (it = factors.begin(); it != factors.end(); it++){
		factor = it->first;
		count = it->second;

		i = n;

		count -= getPowers(i, factor);

		if(count > 0)
			return false;

	}

	return true;

}

int getPowers(long long n, int p){
	
	int result = 0;

	for(long long power = p; power <= n; power *= p)
		result += n/power;

	return result;

}

bool prime (long long n, bool *isPrime){

	if(n < maxN)
		return isPrime[n];

	if(n < 2 || (n != 2 && n%2 == 0))
		return false;
	
	int length = sqrt(n*1.0);

	
	for(int i = 3; i <= length; i += 2){
		if(n%i == 0) return false;
	}

	return true;
}
