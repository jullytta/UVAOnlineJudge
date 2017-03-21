#include<iostream>
#include<string>
#include <cctype>
#include <algorithm>

const int size = 10;

using namespace std;

void press(int line, int col, string grid[size]);
void printGrid(string grid[size]);

int main (void){

	string grid[size];
	string originalGrid[size];
	string name;
	int bestSolution, switches;
	bool allOff;
	
	getline(cin, name);
	name.erase(remove(name.begin(), name.end(), ' '), name.end());

	while(name != "end"){
		
		bestSolution = -1;
		
		for(int i = 0; i < size; i++){
			getline(cin, originalGrid[i]);
		}

		for(int j = 0; j < (1<<10); j++){
			
			switches = 0;

			for(int i = 0; i < size; i++){
				grid[i] = originalGrid[i];
			}

			for(int i = 0; i < size; i++){
				if(j & (1 << i)){
					press(0, i, grid);
					switches++;
				}
			}
			
			for(int i = 1; i < size; i++){
				for(int k = 0; k < size; k++){
					if(grid[i-1][k] == 'O'){
						press(i, k, grid);
						switches++;
					}
				}
			}
			
			allOff = true;
			for(int i = 0; i < size; i++){
				if(grid[size-1][i] != '#'){
					allOff = false;
				}
			}

			if(allOff && (switches < bestSolution || bestSolution == -1)){
				bestSolution = switches;
			}

		}
		
		if(bestSolution > 100)
			bestSolution = -1;
		
		cout << name << " " << bestSolution << endl;
		
		getline(cin, name);
		name.erase(remove(name.begin(), name.end(), ' '), name.end());

		while(name.empty()){
			getline(cin, name);
			name.erase(remove(name.begin(), name.end(), ' '), name.end());
		}

	}

	return 0;

}

void press(int line, int col, string grid[size]){

	if(line-1 >=0){
		if(grid[line-1][col] == '#')
			grid[line-1][col] = 'O';
		else
			grid[line-1][col] = '#';
	}

	if(col-1 >=0){
		if(grid[line][col-1] == '#')
			grid[line][col-1] = 'O';
		else
			grid[line][col-1] = '#';
	}

	if(grid[line][col] == '#')
		grid[line][col] = 'O';
	else
		grid[line][col] = '#';
	
	if(col+1 < size){
		if(grid[line][col+1] == '#')
			grid[line][col+1] = 'O';
		else
			grid[line][col+1] = '#';
	}
	
	if(line+1 < size){
		if(grid[line+1][col] == '#')
			grid[line+1][col] = 'O';
		else
			grid[line+1][col] = '#';
	}
	
}

void printGrid(string grid[size]){

	for(int i = 0; i < size; i++)
		cout << grid[i] << endl;
	cout << "\n";
	
}
