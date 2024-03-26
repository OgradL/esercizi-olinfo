#include <iostream>
#include <stdio.h>
#include <stdlib.h>

using namespace std;

int main() {
	
	freopen("input.txt", "w", stdout);
	
	//int n;
	//cin >> n;
	
	cout << 10000 << " " << 1000 << "\n";
	
	for (int i = 0; i < 10000; i++){
		
		for (int j = 0; j < 1000; j++){
			cout << char(int(rand() % 26) + 97);
		}
		cout << "\n";
		
	}
	
	return 0;
}
