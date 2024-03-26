//Scrivi qui il tuo codice
#include <bits/stdc++.h>

using namespace std;

int main() {
	
	#ifdef EVAL
		freopen("input.txt", "r", stdin);
		freopen("output.txt", "w", stdout);
	#endif
	
	int N;
	
	cin >> N;
	
	vector<int> V(N);
	for (int &i : V) cin >> i;
	
	int b = -1, a = -1;
	
	for (int i = N - 1; i >= 0; i--){
		if (V[i] >= 6){
			a = i;
			break;
		}
	}
	
	for (int i = 0; i < N; i++){
		if (V[i] < 6){
			b = i;
			break;
		}
	}
	
	int ans;
	
	if (b > a || b == -1 || a == -1) ans = -1;
	else {
		ans = a - b + 1;
	}
	
	cout << ans << "\n";
	
}