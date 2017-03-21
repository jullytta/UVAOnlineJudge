#include <stdio.h>
#include <string.h>

#define TEXT_SIZE 100
#define MAX_FIBONACCI 45

int search(int key, int *vector, int vector_size);

int main(void) {
	
	int i, j;
	int n, test_cases, temp, decrypted_size, buffer_size, char_seen;
	int fibonacci[MAX_FIBONACCI];
	int position[TEXT_SIZE];
	char buffer[TEXT_SIZE];
	char decrypted[TEXT_SIZE];
	
	scanf("%d", &test_cases);
	
	fibonacci[0] = 1;
	fibonacci[1] = 2;
	
	for(i = 2; i < MAX_FIBONACCI; i++)
		fibonacci[i] = fibonacci[i-1] + fibonacci[i-2];

	for(i = 0; i < test_cases; i++){
		
		decrypted_size = 0;
		char_seen = 0;

		for(j = 0; j < TEXT_SIZE; j++)
			decrypted[j] = ' ';
		
		scanf("%d", &n);
		
		for(j = 0; j < n; j++){
			
			scanf("%d", &temp);
			position[j] = search(temp, fibonacci, MAX_FIBONACCI);
			
			if(position[j] > decrypted_size)
				decrypted_size = position[j];
			
			if(position[j] == -1){
				j--;
				n--;
			}	
			
		}
		
		fgets(buffer, sizeof(buffer), stdin);
		
		if(decrypted_size != 0)
			decrypted_size++;
		
		fgets(buffer, sizeof(buffer), stdin);

		decrypted[decrypted_size] = '\0';

		buffer_size = strlen(buffer)-1;
	
		for(j = 0; j < buffer_size; j++){
			if(char_seen < n && buffer[j] >= 'A' && buffer[j] <= 'Z'){
				decrypted[(position[char_seen])] = buffer[j];
				char_seen++;
			}
		}
		
		for(j = 0; j < decrypted_size; j++) printf("%c", decrypted[j]);

		printf("\n");
		
	}
	
	return 0;

}

int search(int key, int *vector, int vector_size){
	
	int pos;
	
	for(pos = 0; pos < vector_size; pos++){
		if (vector[pos] == key)
			break;
	}
	
	if(pos == vector_size)
		return -1;
	else return pos;
	
}