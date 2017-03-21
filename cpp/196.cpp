#include<iostream>
#include<string>
#include<sstream>
#include<queue>

const int maxRows = 18280;
const int maxColumns = 1002;
const int nLetters = 26;

using namespace std;

bool done[maxRows][maxColumns];
int spreadsheet[maxRows][maxColumns];
int numberColumn(const char *str);
string convertFormula(string formula, int row, int column);
void printSS(int spreadsheet[maxRows][maxColumns], int rows, int columns);
void init(int rows, int columns);
void check(string formula);
void doFormulas();

queue<string> toDoFormulas;

int main (void){

	int temp, testCases, columns, rows, pos;
	string buffer, delim = " ", token, formula;

	cin >> testCases;
	getline(cin, buffer);

	while(testCases--){
		
		getline(cin, buffer);

		while(buffer.empty()){
			getline(cin, buffer);
			// cout << "New buffer: " << buffer << endl;
		}
		stringstream ss(buffer);
		ss >> columns >> rows;

		init(rows, columns);
		for(int i = 1; i <= rows; i++){
			getline(cin, buffer);
			// cout << "New buffer: " << buffer << endl;
			for(int j = 1; j <= columns; j++){
				pos = buffer.find(delim);
				token = buffer.substr(0, pos);
				buffer.erase(0, pos + delim.length());
				stringstream ss(token);
				ss >> temp;
				if(token[0] == '='){
					formula = convertFormula(token, i, j);
					check(formula);
				}
				else {
					spreadsheet[i][j] = temp;
					done[i][j] = true;
				}
			}
		}
		doFormulas();
		printSS(spreadsheet, rows, columns);
	}

	return 0;

}

int numberColumn(const char *str) {
	int base = 0;
	int count = 0;
	while ((*str) != 0) {
		count = count * nLetters + *str - 'A';
		base = base * nLetters + 1;
		str++;
	}
	return count + base;
}

string convertFormula(string formula, int row, int column){
	int pos, i, r, c;
	char letters[3];
	string token, delim = "+", newFormula;
	stringstream nfss;

	formula.erase(0, 1);
	
	nfss << row << " " << column << " ";

	while(true){
		pos = formula.find(delim);
		token = formula.substr(0, pos);
		formula.erase(0, pos+delim.length());
		
		i = 0;
		while(token[i] >= 'A' && token[i] <= 'Z'){
			letters[i] = token[i];
			i++;
		}
		letters[i] = '\0';

		c = numberColumn(letters);
		token.erase(0, i);
		stringstream ss(token);
		ss >> r;

		nfss << r << " " << c << " ";

		if(pos == (int) string::npos) break;
	}
	
	newFormula = nfss.str();
	return newFormula;

}

void printSS(int spreadsheet[maxRows][maxColumns], int rows, int columns){

	for(int i = 1; i <= rows; i++){
		for(int j = 1; j <= columns-1; j++){
			cout << spreadsheet[i][j] << " ";
		}
		cout << spreadsheet[i][columns] << endl;
	}

}

void init(int rows, int columns){

	for(int i = 0; i <= rows; i++){
		for(int j = 0; j <= columns; j++){
			done[i][j] = false;
			spreadsheet[i][j] = 0;
		}
	}

}

void check(string formula){

	bool possible;
	int row, column, i, j;
	stringstream ss(formula);

	ss >> i >> j;

	spreadsheet[i][j] = 0;
	possible = true;
	while(ss >> row >> column){
		if(!done[row][column]){
			possible = false;
		}
		else {
			spreadsheet[i][j] += spreadsheet[row][column];
		}
	}

	if(possible)
		done[i][j] = true;
	else
		toDoFormulas.push(formula);

}

void doFormulas(){

	string formula;

	while(!toDoFormulas.empty()){
		formula = toDoFormulas.front();
		toDoFormulas.pop();
		check(formula);
	}

}