#include <stdio.h>

#define MAX_TASKS 100

int main(void) {
	
	int m, n, i, j, node, next;
	int degree[MAX_TASKS];
	int adjList[MAX_TASKS][MAX_TASKS];
	int listEnd[MAX_TASKS];
	
	scanf("%d", &n);
	scanf("%d", &m);

	while (n != 0 || m != 0){
	
		for(i = 0; i < n; i++){
			for(j = 0; j < n; j++){
				adjList[i][j] = 0;
			}
		}
		
		for(i = 0; i < n; i++){
			degree[i] = 0;
			listEnd[i] = 0;
		}
	
		for(i = 0; i < m; i++){
			
			scanf("%d", &node);
			scanf("%d", &next);
			
			adjList[node-1][listEnd[node-1]] = next;
			degree[next-1]++;
			listEnd[node-1]++;
			
		}
		
		for(i = 0; i < n; i++){
		
			for(j = 0; j < n; j++){
				if(degree[j] == 0)
					break;
			}
			
			node = j+1;

			printf("%d", node);
	
			for(j = 0; j < listEnd[node-1]; j++){
				degree[(adjList[node-1][j])-1]--;
			}
			
			degree[node-1]--;
			
			if(i != n-1)
				printf(" ");
		
		}
		
		printf("\n");
		
		scanf("%d", &n);
		scanf("%d", &m);

	}
	
	return 0;
	
}