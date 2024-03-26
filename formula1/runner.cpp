#include <iostream>
using namespace std;

int main(){

	int c = 1;
	while (c < 1000){
		system("generator > input.txt");
		system("formula1 < input.txt > output.txt");
		if (c % 15 == 0) {
			cout << c << "\n";
			cout.flush();
		}
		c++;
	}

	return 0;
}