#include <bits/stdc++.h>
#include <time.h>
#include <stdlib.h>
#include <stdio.h>

using namespace std;

int main(){
	
	srand(time(NULL));
	
	freopen("input.txt", "w", stdout);
	
	int N = 30;
	int M = 30;
	
	cout << N << " " << M << "\n";
	
	for (int i = 0; i < M; i++){
		
		int a = rand() % N;
		int b = rand() % N;
		
		cout << a << " " << b << "\n";
		
	}
	
	
	
	return 0;
}
