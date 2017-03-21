#include <stdio.h>
#include <string.h>

int main(void){

	int test_cases, i, j, string_size, result, spree;
	char string[100];

	fgets(string, sizeof(string), stdin);
	sscanf(string, "%d", &test_cases);
	for(i = 0; i < test_cases; i++){
		fgets(string, sizeof(string), stdin);
		string_size = strlen(string) - 1;
		string[string_size] = '\0';

		result = 0;
		spree = 0;

		for(j = 0; j <= string_size; j++){
			if(!spree){
				if(string[j] == 'O') spree = 1;
			}
			else{
				if(string[j] == 'O') spree++;
				else spree = 0;
			}
			result += spree;
		}

		printf("%d\n", result);

	}

	return 0;

}
