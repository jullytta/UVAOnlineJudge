#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define MAX_PANCAKES 30

int read_input(char *string, int *vector);
int find_max(int *vector, int tam);
int verify_increasing(int *vector, int tam);
void flip(int *vector, int position, int tam);
void print_vector(int tam, int vector[tam]);

int main(void){

	int pancakes_stack[MAX_PANCAKES];
	int tam, max_position, fix, done, bottom, top;
	char string[124];


	while(fgets(string, sizeof(string), stdin) != NULL){

		tam = read_input(string, pancakes_stack);

		print_vector(tam, pancakes_stack);
		
		fix = tam;

		done = 0;
		top = 0;
		bottom = tam-1;

		while(!done && fix > 1){

			max_position = find_max(pancakes_stack, fix);

			if(max_position == top){
				printf("%d ", tam-bottom);
				flip(pancakes_stack, tam-bottom, tam);
				fix--;
				bottom--;
			}
			else if(max_position == bottom){
				fix--;
				bottom--;
			}
			else {
				printf("%d ", tam-max_position);
				flip(pancakes_stack, tam-max_position, tam);
			}

			done = verify_increasing(pancakes_stack, tam);

		}
	
		printf("0\n");

	}
	

	return 0;

}

int read_input(char *string, int *vector){

	int tam = 1, i, temp;
	char *buffer;

	buffer = strtok(string, " ");

	sscanf(buffer, "%d", &temp);
	vector[0] = temp;

	for(i = 1; ; i++){
		buffer = strtok(NULL, " ");

		if(buffer == NULL)
			break;
		else
			sscanf(buffer, "%d", &temp);
		vector[i] = temp;
		tam++;
	}

	return tam;

}


int find_max(int *vector, int tam){

	int max_position = 0, max = 0, i;

	for (i = 0; i < tam; i++){
		if(vector[i] > max){
			max = vector[i];
			max_position = i;
		}
	}

	return max_position;

}


int verify_increasing(int *vector, int tam){

	int i;

	for(i = 0; i < tam-1; i++){
		if(vector[i] > vector[i+1])
			return 0;
	}

	return 1;

}


void flip(int *vector, int position, int tam){

	int temp, final = tam - position, i;

	for(i = 0; i < final; i++){
		temp = vector[i];
		vector[i] = vector[final];
		vector[final] = temp;
		final--;
	}

}

void print_vector(int tam, int vector[tam]){
	
	int i;

	for(i = 0; i < tam; i++)
		printf("%d ", vector[i]);
	printf("\n");

}
