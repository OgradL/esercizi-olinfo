#include <iostream>
#include <vector>
using namespace std;

void scavi(int R, int C, int Q, vector<int> &x1, vector<int> &y1, vector<int> &x2, vector<int> &y2, vector<int> &P, vector<vector<int>> &terreno){
	
	vector<vector<int>> delta(R+1, vector<int>(C+1, 0));
	
	int q = 0;
	while (q < Q){
		delta[x1[q]][y1[q]] += P[q];
		delta[x1[q]][y2[q]+1] -= P[q];
		delta[x2[q]+1][y1[q]] -= P[q];
		delta[x2[q]+1][y2[q]+1] += P[q];
		q++;
	}

	for (int i = 1; i < R; i++){
		delta[i][0] += delta[i-1][0]; 
	}
	for (int i = 1; i < C; i++){
		delta[0][i] += delta[0][i-1]; 
	}

	for (int i = 1; i < R; i++){
		for (int j = 1; j < C; j++){
			delta[i][j] += delta[i-1][j] + delta[i][j-1] - delta[i-1][j-1];
		}
	}

	for (int i = 0; i < R; i++){
		for (int j = 0; j < C; j++){
			terreno[i][j] = delta[i][j];
		}
	}

}
