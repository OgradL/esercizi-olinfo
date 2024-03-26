#include <iostream>
#include <vector>
#include <queue>
using namespace std;

struct ar{
	int fr, to, h;
};

void risolvi(int N, int M, int A[], int B[], int H[], long long risposta[]){

	vector<vector<ar>> G(N+1);
	for (int i = 0; i < M; i++){
		G[A[i]].push_back((ar){A[i], B[i], H[i]});
		G[B[i]].push_back((ar){B[i], A[i], H[i]});
	}

	priority_queue<ar> pq;
	pq.push((ar){0, 0, 0});

	vector<int> v(N+1, 0);
	vector<int> t(N+1, 0), f(N+1, 0);

	int t = 0;
	ar n;
	while (!pq.empty()){
		n = pq.top();
		pq.pop();

		// t += 

		if (v[n.to])
			continue;
		v[n.to] = 1;


		

	}


}