#include <iostream>
#include <string>

const int maxSize = 1000;

using namespace std;

void imprime_vetor(int tam, int vetor[]){
    int i;
 
    cout << "[ ";
    for(i = 0; i < tam; i++)
        cout << vetor[i] << " ";
    cout << "]\n";

}

int main (){

	int n, bufferSize, intaSize, intbSize, fracaSize, fracbSize;
	int inta[maxSize], intb[maxSize], fraca[maxSize], fracb[maxSize];
	string buffer;

	cin >> n;
	getline(cin, buffer);

	for(int k = 0; k < n; k++){

		getline(cin, buffer);

cout << "Case " <<k+1<<", buffer: " << buffer << endl;

		bufferSize = buffer.size();
		intaSize = intbSize = fracaSize = fracbSize = 0;

		for(int i = bufferSize-1; i >= 0; ){
			
			while(i >= 0 && buffer[i] != '.'){
				if(buffer[i] >= '0' && buffer[i] <= '9'){
					fracb[fracbSize] = buffer[i] - '0';
					fracbSize++;
				}
				i--;
			}

			i--;

			while(i >= 0 && buffer[i] != ' '){
				if(buffer[i] >= '0' && buffer[i] <= '9'){
					intb[intbSize] = buffer[i] - '0';
					intbSize++;
				}
				i--;
			}

			i--;

			while(i >= 0 && buffer[i] != '.'){
				if(buffer[i] >= '0' && buffer[i] <= '9'){
					fraca[fracaSize] = buffer[i] - '0';
					fracaSize++;
				}
				i--;
			}

			i--;

			while(i >= 0 && buffer[i] != ' '){
				if(buffer[i] >= '0' && buffer[i] <= '9'){
					inta[intaSize] = buffer[i] - '0';
					intaSize++;
				}
				i--;
			}

		}

		cout << "Frac A: ";
		imprime_vetor(fracaSize, fraca);
		cout << "Int A: ";
		imprime_vetor(intaSize, inta);
		cout << "Frac B: ";
		imprime_vetor(fracbSize, fracb);
		cout<< "Int B: ";
		imprime_vetor(intbSize, intb);

	}

	return 0;

}
