#include <iostream>

using namespace std;

int main(){

	unsigned int x, y;
	int dx, dy, carry, n;

	cin >> x;
	cin >> y;


	while(x != 0 || y != 0){

		n = 0;
		carry = 0;

		while(x != 0 || y != 0){
			dx = x % 10;
			dy = y % 10;

			if((dx + dy + carry) >= 10){
				carry = (dx + dy + carry)/10;
				n++;
			}
			else {
				carry = 0;
			}

			x = x/10;
			y = y/10;

		}

		if(n == 0)
			cout << "No carry operation.\n";
		else if(n == 1)
			cout << "1 carry operation.\n";
		else
			cout << n << " carry operations.\n";

		cin >> x;
		cin >> y;

	}

	return 0;

}
