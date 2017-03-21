#include<stdio.h>
#include<stdlib.h>
#include<string.h>

void print_binary(int);
int xor(int, int);

int main(void){

	int test_cases, i, j, case_done = 0;
	char string[100];
	char *endpointer;
	char *buffer;
	int a, b, c, d;

	fgets(string, sizeof(string), stdin);
	sscanf(string, "%d", &test_cases);

	for(i = 0; i < test_cases; i++){
		fgets(string, sizeof(string), stdin);

		if(case_done)
				printf("\n");

		case_done = 0;
		
		buffer = strtok(string, " ");
		a = (int) strtol(buffer, &endpointer, 2);

		buffer = strtok(NULL, " ");
		b = (int) strtol(buffer, &endpointer, 2);

		print_binary(a); printf(" "); print_binary(b); printf("\n");
		
		while(b != 0 && !case_done){
			c = xor(a, b);
			d = a & b;

			a = c;
			b = 2*d;

			print_binary(a); printf(" ");

			if(b >= 0){
				print_binary(b); printf("\n");
				if( b == 0 )
					case_done = 1;
			}
			else {
				printf("overflow\n"); case_done = 1;
			}

		}

	}


	return 0;

}

void print_binary(int v) {

	int i;

	for(i = (sizeof(v)*8)-2; i >= 0; i--)
		putchar('0' + ((v >> i) & 1));

}

int xor(int a, int b){

	return ((~a & b) | (a & ~b));

}
