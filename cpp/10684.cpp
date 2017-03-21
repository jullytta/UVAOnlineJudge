#include<iostream>

const int maxN = 10001;

using namespace std;

int main (void){
	
	int n, maxStreak, temp, streak;
	
	cin >> n;
	
	while(n != 0){
		
		maxStreak = 0;
		streak = 0;
		
		for(int i = 0; i < n; i++){
			cin >> temp;
			streak += temp;
			if(streak > maxStreak)
				maxStreak = streak;
			else if(streak < 0)
				streak = 0;
		}
		
		if(maxStreak == 0)
			cout << "Losing streak.\n";
		else
			cout << "The maximum winning streak is " << maxStreak << ".\n";
		
		cin >> n;
		
	}
	
	return 0;
	
}
