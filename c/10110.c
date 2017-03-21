#include<stdio.h>
#include<math.h>

int main(void){

	long long int n;

	while(1){

		scanf("%Ld", &n);

		if(n == 0)
			break;

		if(sqrt(n) == floor(sqrt(n)))
			printf("yes\n");
		else printf("no\n");

	}

	return 0;

}
