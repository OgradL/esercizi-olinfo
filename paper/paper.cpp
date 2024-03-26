#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int paper(int N, int M, int* from, int* to){

	vector<vector<int>> G(N);
	int a, b;
	for (int i = 0; i < M; i++){
		G[to[i]-1].push_back(from[i]-1);
	}

	



	return 0;
}