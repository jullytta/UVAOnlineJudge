#include<iostream>

using namespace std;

void gdc(int *a, int *b, int *x, int *y, int *d);

int main(void){

	int a, b, x, y, d;

	while(cin >> a >> b){

		gdc(&a, &b, &x, &y, &d);

		cout << x << " " << y << " " << d << endl;
		
	}

	return 0;

}

void gdc(int *a, int *b, int *x, int *y, int *d){

	int c, xl, yl, dl;

	if(b > a)
		gdc(b, a, x, y, d);

	if(*b == 0){
		*d = *a;
		*x = 1;
		*y = 0;
	} else {
		c = (*a)%(*b);
		dl = (*a)/(*b);
		gdc(b, &c, &xl, &yl, d);
		*y = xl - dl*yl;
		*x = yl;
	}
}
