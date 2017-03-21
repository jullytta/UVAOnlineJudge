#include<iostream>

const int consecutiveMonths = 5;

using namespace std;

int main (void){
	
	int s, d, count, sum;
	
	while(cin >> s >> d){
	
		count = 0;
		sum = 0;
	
		count++;
		sum += s;
		while(((sum - ((consecutiveMonths - count)*d)) < 0) && (count <= consecutiveMonths)){
			count++;
			sum += s;
		}
		
		count--;
		
		if(count == 0){
			cout << "Deficit\n";
			continue;
		}
		
		sum = 2*((count*s)-((consecutiveMonths-count)*d));

		if(count >= 2)
			sum += 2*s;
		else if(count == 1){
			sum += s;
			sum -= d;
		}
		
		if(sum > 0)
			cout << sum << "\n";
		else
			cout << "Deficit\n";
	}

	return 0;
	
}
