#include<stdio.h>
#include<stdlib.h>
#include<string.h>


#define BUFFER_SIZE 8192

int read_leaf(char *buffer, int pos);
int verify_buffer(char *buffer);
int verify_empty_line(char *buffer);


int sum;
int target;
int case_done;


int main(void){

	int i;
	char buffer[BUFFER_SIZE];
	char temp[BUFFER_SIZE];
	int buffer_size;
	int must_recharge;
	int count;
	int negative_flag;
	char number[10];

	while(fgets(buffer, sizeof(buffer), stdin) != NULL){

		count = 0;
		negative_flag = 1;

		for(i = 0; i < 10; i++)
			number[i] = ' ';
		number[10] = '\0';
		
		while((sscanf(buffer, "%d", &target) == -1)){
			if((fgets(buffer, sizeof(buffer), stdin) == NULL))
				exit(0);
		}

		buffer_size = strlen(buffer);

		for(i = 0; i < buffer_size; i++){
			if(buffer[i] == '-')
				negative_flag = -1;
			if(buffer[i] >= '0' && buffer[i] <= '9'){
				number[count] = buffer[i];
				count++;
			}
			else if (count != 0)
				break;
		}

		sscanf(number, "%d", &target);
		target *= negative_flag;
			

		sum = 0;
		case_done = 0;
		must_recharge = 0;

		while(!verify_empty_line(buffer)){
			if(fgets(buffer, sizeof(buffer), stdin) == NULL)
				exit(0);
		}

		
		must_recharge = verify_buffer(buffer);

		while(must_recharge != 0){
			fgets(temp, sizeof(temp), stdin);
			must_recharge += verify_buffer(temp);
			strcat(buffer, temp);
		}

		buffer_size = strlen(buffer);

		for(i = 0; i < buffer_size; i++){
			if(buffer[i] == '('){
				read_leaf(buffer, i+1);
				break;
			}
		}

		if(case_done == 0)
			printf("no\n");
	}

	return 0;

}


int verify_buffer(char *buffer){

	int i;
	int charge;
	int buffer_size;

	charge = 0;
	buffer_size = strlen(buffer);

	for(i = 0; i < buffer_size; i++){
		if(buffer[i] == '(')
			charge++;
		else if(buffer[i] == ')')
			charge--;
	}

	return charge;

}

int verify_empty_line(char *buffer){

	int i;
	int buffer_size;

	buffer_size = strlen(buffer);
	
	for(i = 0; i < buffer_size; i++){
		if(buffer[i] == '(')
			return 1;
	}
	
	return 0;

}


int read_leaf(char *buffer, int pos){

	int buffer_size;
	int i;
	int num_filhos;
	int balance;
	int leaf_number;
	int count;
	int right_child, left_child;
	int negative_flag;
	char number[10];

	buffer_size = strlen(buffer);
	num_filhos = 0;
	balance = 0;
	leaf_number = 0;
	count = 0;
	negative_flag = 1;

	for(i = 0; i < 10; i++)
		number[i] = ' ';
	number[10] = '\0';

	for(i = pos; i <= buffer_size && case_done == 0; i++){

		if(buffer[i] == '-' && leaf_number == 0)
			negative_flag = -1;

		if(leaf_number == 0 && buffer[i] >= '0' && buffer[i] <= '9'){
			number[count] = buffer[i];
			count++;
		}

		if(num_filhos == 2){
			if(left_child == 0 && right_child == 0){
				if(sum == target && case_done == 0){
					printf("yes\n");
					case_done = 1;
				}
			}
			
			sum -= leaf_number;

			break;

		}

		if(buffer[i] == '('){

			if(leaf_number == 0){
				if(sscanf(number, "%d", &leaf_number) == -1)
					return 0;
				else {
					leaf_number *= negative_flag;
					sum += leaf_number;
				}
			}
		
			if(balance == 0){
				num_filhos++;
				if(num_filhos == 1)
					left_child = read_leaf(buffer, i+1);
				else 
					right_child = read_leaf(buffer, i+1);
			}
			
			balance++;

		}
		else if(buffer[i] == ')'){

			if(sscanf(number, "%d", &leaf_number) == -1)
				return 0;
			else
				leaf_number *= negative_flag;
			
			balance--;

		}

	}

	return 1;

}
