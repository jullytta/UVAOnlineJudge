#include<stdio.h>

#define MAX_COACHES 1024


void push(int key, int *top, int *stack);
int pop(int *top, int *stack);
int is_it_possible(int size, int *goal);

int main(void){

	int coaches_out[MAX_COACHES];
	int num_coaches;
	int i;
	int result;

	while(1){

		scanf("%d", &num_coaches);
			
		if(num_coaches == 0) break;
		
		while(1){
		
			scanf("%d", &coaches_out[0]);

			if(coaches_out[0] == 0) break;
		
			for(i = 1; i < num_coaches; i++)
				scanf("%d", &coaches_out[i]);

			result = is_it_possible(num_coaches, coaches_out);

			if(result == 1)
				printf("Yes\n");
			else
				printf("No\n");

		}

		printf("\n");

	}

	return 0;

}

void push(int key, int *top, int *stack){
	stack[(*top)] = key;
	(*top)++;
}

int pop(int *top, int *stack){
	(*top)--;
	return stack[(*top)+1];
}

int is_it_possible(int size, int *goal){

	int stack[MAX_COACHES];
	int top;
	int next;
	int i;

	top = 0;
	next = 1;

	for(i = 0; i < size; ){
		
		if(next <= goal[i]){
			push(next, &top, stack);
			next++;
		}
		else if(stack[top-1] == goal[i]){
			pop(&top, stack);
			i++;
		}
		else return 0;

	}

	if(top == 0)
		return 1;
	else
		return 0;

}
