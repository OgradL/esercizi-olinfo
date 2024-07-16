#include <iostream>
#include <vector>

using namespace std;
using ll = long long;
const int N = 200, M = 69;

vector<vector<char>> solve(ll K){

	vector<vector<char>> ans(N, vector<char>(M, '#'));

	for (int i = 0; i <= 60; i++){
		if (i != 0){
			ans[N-1-i*3][M-1-i] = '.';
			ans[N-2-i*3][M-1-i] = '.';
			ans[N-1-i*3][M-2-i] = '.';
			ans[N-2-i*3][M-2-i] = '.';
			ans[N-3-i*3][M-2-i] = '.';
		} else {
			ans[N-1-i*3][M-2-i] = '.';
			ans[N-2-i*3][M-2-i] = '.';
			ans[N-3-i*3][M-2-i] = '.';
		}
	}

	for (int i = 0; i < N; i++){
		ans[i][0] = '.';
	}

	for (int i = 0; i <= 60; i++){
		if ((K & (1LL<<i)) != 0){
			for (int j = 0; j < M-i-1; j++){
				ans[N-2-i*3][j] = '.';
			}
		}
	}
	ans[N-1][M-1] = '.';

	return ans;
}
