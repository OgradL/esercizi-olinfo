//crivi qui il tuo codice
#include <bits/stdc++.h>

using namespace std;

int visit(int n, vector<vector<int> >& citi, vector<bool>& visi){
	
	if (visi[n]){
		return 0;
	}
	visi[n] = true;
	int a;
	for (int i = 0; i < citi[n].size(); i++){
		a = visit(citi[n][i], citi, visi);
	}
	
	return 1;
}

int main() {
	
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	
	int N, M;
	
	cin >> N >> M;
	
	vector<vector<int> > citi(N, vector<int>(0));
	
	int A, B;
	
	for (int i = 0; i < M; i++){
		
		cin >> A >> B;
		
		citi[A].push_back(B);
		
		citi[B].push_back(A);
		
	}
	
	vector<bool> visi(N, false);
	
	int ans = 0;
	
	for (int i = 0; i < N; i++){
		ans += visit(i, citi, visi);
	}
	
	cout << ans - 1 << "\n";
	
}