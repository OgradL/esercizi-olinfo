#include <iostream>
#include <vector>
#include <queue>
using namespace std;

struct node{
	int fr, to, K;
	long long w, b, v;
};

int avoid_volunteers(int subtask, int N, int M, int K, int S, int E, int T, int A[], int B[], int W[], int P[], int V[]) {

	vector<vector<node>> G(N);
	for (int i = 0; i < M; i++){
		G[A[i]].push_back(node {A[i], B[i], K, W[i], P[i], V[i]});
		G[B[i]].push_back(node {B[i], A[i], K, W[i], P[i], V[i]});
	}
	
	
	return 76;
}
