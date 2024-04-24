#include <iostream>
#include <vector>
#include <queue>
using namespace std; 

int check(int N, int M, int T[], int mid){
	priority_queue<int, vector<int>, greater<int>> pq;

	int t = 0;
	for (int i = 0; i < N; i++){
		t = 0;
		if (i >= mid){
			t = pq.top();
			pq.pop();
		}
		pq.push(t + T[i]);
	}

	int biggest = 0;
	while (pq.size()){
		biggest = pq.top();
		pq.pop();
	}

	return biggest <= M;
}

int gpu(int N, int M, int T[]){

	int lo = 0, hi = N, mid;
	while (lo + 1  < hi){
		mid = (lo + hi) / 2;
		if (check(N, M, T, mid))
			hi = mid;
		else
			lo = mid;
	}

	return hi;
}