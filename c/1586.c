#include <stdio.h>
#include <string.h>

double weight(char);

int main(void){

	int test_cases, i, j, string_size, letter, number;
	char string[100];
	double result;

	fgets(string, sizeof(string), stdin);
	sscanf(string, "%d", &test_cases);
	
	for(i = 0; i < test_cases; i++){
		fgets(string, sizeof(string), stdin);
		string_size = strlen(string) - 1;
		string[string_size] = '\0';

		result = 0;
		number = 0;
		letter = string[0];

		for(j = 1; j <= string_size; j++){
			if(string[j] >= '0' && string[j] <= '9'){
				if(string[j+1] >= '0' && string[j+1] <= '9'){
					number = (string[j] - '0')*10 + (string[j+1] - '0');
					j++;
				} else number = string[j]-'0';
			}
			else if((string[j] == 0) || (string[j] >= 'A')){
				if(number == 0) number = 1;
				result += weight(letter)*number;
				number = 0;
				letter = string[j];
			}
		}

		printf("%.3f\n", result);

	}

	return 0;

}

double weight(char element){
	
	if(element == 'C')
		return 12.01;
	else if (element == 'H')
		return 1.008;
	else if (element == 'O')
		return 16.00;
	else if (element == 'N')
		return 14.01;
	else 
		return -1;

}
