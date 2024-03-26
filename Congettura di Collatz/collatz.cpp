#include <stdio.h>
#include <assert.h>
#include <iostream>

using namespace std;

int N;

int main() {
	
	freopen("input1.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	
	cin >> N;
	
	int current = N;
	int count = 1;
	
	while (current != 1){
		count++;
		if (current % 2 == 0){
			current /= 2;
		} else {
			current = (current * 3) + 1;
		}
		
	}
	
	cout << count;
	
	return 0;
}
