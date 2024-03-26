#include <bits/stdc++.h>
#include <iostream>
#include <vector>

using namespace std;

struct arco {
	int fine;
	int peso;
};

void mincammino(int N, int M, vector<int> X, vector<int> Y, vector<int> P, vector<int> &D) {
	vector<arco> list[N];
	D.resize(N);
	for (int i = 0; i < N; i++) {
		D[i] = -1;
	}
	// Build adjacency list
	for (int i = 0; i < M; i++) {
		arco tmp;
		tmp.fine = Y[i];
		tmp.peso = P[i];
		list[X[i]].push_back(tmp);
	}
	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
	pq.push(make_pair(0, 0));
	D[0] = 0;
	while (!pq.empty()) {
		pair<int, int> nodo = pq.top();
		pq.pop();
		for (arco next: list[nodo.second]) {
			if (nodo.first + next.peso < D[next.fine] || D[next.fine] == -1) {
				D[next.fine] = nodo.first + next.peso;
				pq.push(make_pair(D[next.fine], next.fine));
			}
		}
	}
}
