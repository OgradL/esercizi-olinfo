#include <iostream>
#include <vector>
using namespace std;

vector<vector<int>> d;
vector<int> d2;
void inizializza(int N, int M){
	d.resize(M+1);
	d2.assign(M+1, 0);
	for (int i = 2; i <= M; i++)
		if (d[i].size() <= 1)
			for (int j = i; j <= M; j += i)
				d[j].push_back(i);
}


int controlla(int N){
	int ans = 0;
	for (int i = 0; i < d[N].size(); i++){
		ans = (d2[d[N][i]]==0)?ans:d2[d[N][i]];
	}
	if (!ans){
		for (int i = 0; i < d[N].size(); i++){
			d2[d[N][i]] = N;
		}
	}
	return ans;
}