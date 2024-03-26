#include<bits/stdc++.h>
using namespace std;

int best_score(int N, int K, vector<int> &monete);

int main(){
	int N, K;
	cin >> N >> K;
	vector<int> v(N);
	for (int i = 0; i < N; i++)
		cin >> v[i];
	cout << best_score(N, K, v) << '\n';
}
