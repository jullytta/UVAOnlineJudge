#include<stdio.h>
#include<stdlib.h>


int main(void){

	int n, k, i, survivor, deadman, others_alive, safe_start;
	int vector[100];

	while(1){

		scanf("%d%d", &n, &k);

		if(n == 0 && k == 0) break;

		for(i = 0; i < n; i++)
			vector[i] = i+1;

		deadman = (k-1)%n;
		others_alive = n-1;
		if(n == 1){
			others_alive = 0;
			printf("1\n");
		}

		while(others_alive){

			survivor = deadman;
			vector[deadman] = -1;
			others_alive--;

			for(i = 0; i < k; ){
				survivor = (survivor+1)%n;
				if(vector[survivor] != -1)
					i++;
			}

			if(others_alive == 0){
				safe_start = (n + 1 - (vector[survivor] - 1));
				printf("%d\n", safe_start);
				break;
			}
		
			vector[deadman] = vector[survivor];
			vector[survivor] = -1;

			for(i = 0; i < k; ){
				deadman = (deadman+1)%n;
				if(vector[deadman] != -1)
					i++;
			}

		}

	}

	return 0;

}
