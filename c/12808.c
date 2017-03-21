#include <stdio.h>
#include <math.h>

int main(void){

	int test_cases, i;
	double L, D, H, V;
	double gravity = 9.81, time, S;

	scanf("%d", &test_cases);
	for(i = 0; i < test_cases; i++){
		scanf("%lf", &L);
		scanf("%lf", &D);
		scanf("%lf", &H);
		scanf("%lf", &V);

		time = sqrt((2*H/1000)/gravity);

		S = V*time;

		if((S < D - 500) || (S > D + L + 500)) printf("FLOOR\n");
		else if((S <= D + 500) || ( S >= D + L - 500)) printf("EDGE\n");
		else printf("POOL\n");

	}

	return 0;

}
