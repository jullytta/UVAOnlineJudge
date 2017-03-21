#include<iostream>
#include<algorithm>

const int maxN = 1000000;

using namespace std;

int numbers[maxN], M[maxN], M_id[maxN], nextN[maxN];

void printSequence(int key);

int main (void){

	int size = 0, end = 0;
	
	for(int i = 0; ; i++){
		if(!(cin >> numbers[i])) break;

		int position = lower_bound(M, M + size, numbers[i]) - M;
		M[position] = numbers[i];
		M_id[position] = i;
		if(position > 0)
			nextN[i] = M_id[position-1];
		else 	nextN[i] = -1;
		if(position == size){
			size++;
			end = i;
		}
	}
	
	cout << size << "\n-\n";
	printSequence(end);

	return 0;
	
}


void printSequence(int key){
	if(key < 0) return;
	printSequence(nextN[key]);
	cout << numbers[key] << endl;

}
