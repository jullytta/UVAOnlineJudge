#include <iostream>

using namespace std;

long reverseNumber(long number);

int main(){
	
	int testCases;
	long number;
	long reverse;
	long sum;
	int iterations;
	
	cin >> testCases;
	
	for(int i = 0; i < testCases; i++){
		
		iterations = 0;
		cin >> number;
		reverse = reverseNumber(number);	
		
		while(1){
			
			if(number == reverse){
				cout << iterations << " " << number << "\n";				
				break;
			}
			
			iterations++;
			
			sum = number + reverse;

			number = sum;
			reverse = reverseNumber(number);
		
		}
		
	}
	
	return 0;
	
}

long reverseNumber(long number){
	
	long reverse = 0;
	
	while(number != 0){	
		reverse = reverse * 10;
		reverse += number%10;
		number = number/10;
	}
	
	return reverse;
	
}
