#include <bits/stdc++.h>

using namespace std;

int main(){
	
	#ifdef EVAL
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	#endif
	
	
	int N;
	
	cin >> N;
	
	vector<int> C(N);
	
	int n_u = 0, n_d = 0;
	
	for (int i = 0; i < N; i++){
		cin >> C[i];
		
		if (C[i] == 2){
			n_d++;
		}
		if (C[i] != 0){
			n_u++;
		}
		
	}
	
	int tot = n_u + n_d;
	
	
	
	double ans = float(n_d) * (float(n_d) / 2.0 + 0.5) / (float)tot;
	
	cout << ans << "\n";
	
	return 0;
}
