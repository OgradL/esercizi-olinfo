#include <vector>
#include <iostream>
#include <unordered_map>
using namespace std;

int prev_element(int i, int N, vector<int>& A, unordered_map<int, bool>& M){ // O(n)
	i--;
	while (M[i] && i >= 0){
		i--;
	}

	return max(i, 0);
}

int next_element(int i, int N, vector<int>& A, unordered_map<int, bool>& M){ // O(n)
	i++;
	while (M[i] && i < N){
		i++;
	}
	// cout << "next_element " << i << "\n";
	if (i == N) return -1;
	return i;
}

bool check(int i, int N, vector<int>& A, unordered_map<int, bool>& M){ // O(3n)
	if (i + 2 >= N) return false;

	int V1, V2, V3;
	V1 = i;
	V2 = next_element(V1, N, A, M);
	V3 = next_element(V2, N, A, M);
	if (V2 == -1 || V3 == -1) return false;
	V1 = A[V1];
	V2 = A[V2];
	V3 = A[V3];

	// cout << A[i] << " " << A[i+1] << " " << A[i+2] << "\n";
	return (V1 ^ V2 ^ V3) == 0;
}

vector<int> dp;

int f(int i, int N, vector<int>& A, unordered_map<int, bool>& M, int can_dp){ // O(2^n)
	// cout << i << "\n";
	if (i >= N || i <= -1) return 0;

	if (dp[i] != -1 && can_dp <= 0) return dp[i];
	
	// for (int i = 0; i < N; i++) cout << M[i] << " ";
	// cout << "\n";

	// cout << i << "\n";

	int c1 = 0, c2 = 0;

	int ne = next_element(i, N, A, M);
	// cout << "next element " << ne << "\n";

	c1 = f(ne, N, A, M, can_dp - 1);

	// cout << "done forwording " << i << "\n";

	if (check(i, N, A, M)){

		// cout << "working " << i << "\n";
		int V1, V2, V3;
		V1 = i;
		V2 = next_element(V1, N, A, M);
		V3 = next_element(V2, N, A, M);
		// cout << V1 << " " << V2 << " " << V3 << "\n";
		if (!(V2 == -1 || V3 == -1)){
			M[V1] = true;
			M[V2] = true;
			M[V3] = true;

			// cout << "found at " << i << "\n";

			int i1 = prev_element(i, N, A, M);
			int i2 = prev_element(i1, N, A, M);
			
			c2 = f(i2, N, A, M, 2) + 3;

			M[V1] = false;
			M[V2] = false;
			M[V3] = false;
		}
	}
	// cout << "returning " << i << " | " << c1 << " - " << c2 << "\n";
	if (can_dp <= 0) dp[i] = max(c1, c2);
	return max(c1, c2);
}

int conta(int N, vector<int> V) {
	
	dp = vector<int>(N, -1);

	unordered_map<int, bool> M;
	int count = f(0, N, V, M, 0);

	// int v1, v2, v3;
	// v1 = 3;
	// v2 = next_element(v1, N, V, M);
	// v3 = next_element(v2, N, V, M);

	// cout << v1 << " " << v2 << " " << v3 << "\n";


	/*
	for (int i = 0; i < V.size(); i++){

		// if (M[i]) continue;

		if (check(i, V)){
			// M[i] = true;
			// M[i+1] = true;
			// M[i+2] = true;
			V.erase(V.begin() + i, V.begin() + i + 2);
			i = max(0, i-3);
			count++;
		}

	}*/

	return count;
}
