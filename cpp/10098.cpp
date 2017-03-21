#include<iostream>
#include<string>
#include<sstream>
#include<algorithm>

using namespace std;

int main (void){

	string buffer;
	int n;
	
	getline(cin, buffer);
	
	stringstream ss;
	ss << buffer;
	ss >> n;

	for(int i = 0; i < n; i++){
		
		getline(cin, buffer);
		
		sort(buffer.begin(), buffer.end());
		
		cout << buffer << endl;
		
		while (next_permutation(buffer.begin(), buffer.end())){
			cout << buffer << endl;
		}
		
		cout << "\n";
		
	}

	return 0;

}
