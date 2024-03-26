#include <bits/stdc++.h>

using namespace std;

int main(){
	
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);
	
	int N;
	
	cin >> N;
	
	vector<int> P(N);
	
	for (int i = 0; i < N; i++){
		cin >> P[i];
	}
	
	int count = N;
	
	for (int i = 0; i < N; i++){
		if (P[i] == 0){
			if (P[max(i - 1, 0)] > 1){
				count--;
				P[max(i - 1, 0)]--;
			} else if (P[min(i + 1, N - 1)] > 1){
				count--;
				P[min(i + 1, N - 1)]--;
			}
		} else {
			count--;
		}
		
	}
	
	cout << count << "\n";
	
	return 0;
}
