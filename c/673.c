#include <stdio.h>
#include <string.h>

int main(void){

	int test_cases, i, j, string_size, end;
	char string[150];
	char stack[150];

	fgets(string, sizeof(string), stdin);
	sscanf(string, "%d", &test_cases);

	for(i = 0; i < test_cases; i++){
		fgets(string, sizeof(string), stdin);
		string_size = strlen(string) - 1;
		string[string_size] = '\0';
		end = 0;

		for(j = 0; j <= string_size; j++){
			
			if(string[j] == 0){
				if(end == 0)
					printf("Yes\n");
				else
					printf("No\n");
				break;
			}
		
			if(string[j] == ')'){
				if(stack[end-1] == '(')		
					end--;
				else{ printf("No\n"); break; }
			}

			if(string[j] == ']'){
				if(stack[end-1] == '[')		
					end--;
				else{ printf("No\n"); break; }
			}

			if(string[j] == '('){ stack[end] = '('; end++; }
			if(string[j] == '['){ stack[end] = '['; end++; }

		}

	}

	return 0;

}
