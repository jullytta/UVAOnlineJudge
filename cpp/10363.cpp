#include<iostream>
#include<string>
#include<sstream>

const int DIMENSION = 3;

using namespace std;

bool won(int player, int grid[DIMENSION][DIMENSION]);

int main (void){

	bool xwon, owon, valid;
	int n, xs, os, pos;
	int grid[DIMENSION][DIMENSION];
	string buffer;
	
	getline(cin, buffer);

	stringstream ss;

	ss << buffer;
	
	ss >> n;

	for(int i = 0; i < n; i++){
		
		xs = os = 0;
		xwon = owon = valid = false;
		
		getline(cin, buffer);
		while(buffer.empty())
			getline(cin, buffer);
		
		for(int j = 0; j < DIMENSION; j++){
		
			pos = 0;
			for(int k = 0; pos < DIMENSION; k++){
				switch(buffer[k]){
					case '.':
						grid[j][pos] = -1;
						pos++;
						break;
					case 'O': case 'o':
						grid[j][pos] = 0;
						pos++;
						os++;
						break;
					case 'X': case 'x':
						grid[j][pos] = 1;
						pos++;
						xs++;
						break;
					default:
						break;
				}
				
			}
			
			getline(cin, buffer);
			
		}
		
		xwon = won(1, grid);
		owon = won(0, grid);

		if(!owon && !xwon){
			if(xs == os || xs-1 == os)
				valid = true;
		}
		else if (owon || xwon){
			if(xwon){
				if(xs-1 == os)
					valid = true;
			} else {
				if(xs == os)
					valid = true;
			}

		}
		
		if(valid)
			cout << "yes" << endl;
		else
			cout << "no" << endl;
			
	}

	return 0;

}

bool won(int player, int grid[DIMENSION][DIMENSION]){

	int match;

	for(int i = 0; i < DIMENSION; i++){
		match = 0;
		for(int j = 0; j < DIMENSION; j++){
			if(grid[i][j] == player)
				match++;
		}
		if(match == DIMENSION)
			return true;
	}
	
	for(int j = 0; j < DIMENSION; j++){
		match = 0;
		for(int i = 0; i < DIMENSION; i++){
			if(grid[i][j] == player)
				match++;
		}
		if(match == DIMENSION)
			return true;
	}
	
	match = 0;
	for(int k = 0; k < DIMENSION; k++){
		if(grid[k][k] == player)
			match++;
	}
	if(match == DIMENSION)
		return true;
		
	match = 0;
	for(int k = 0; k < DIMENSION; k++){
		if(grid[k][DIMENSION-(k+1)] == player)
			match++;
	}
	if(match == DIMENSION)
		return true;
	
	return false;
	
}
