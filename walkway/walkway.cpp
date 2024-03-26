#include <bits/stdc++.h>

using namespace std;


int main(){
	
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	
	int N, K;
	cin >> N >> K;
	
	vector<int> H;
	H.resize(N);
	for (int i = 0; i < N; i++){
		cin >> H[i];
	}
	
	
	sort(H.begin(), H.end());
	
	
	int result = 1000000;
	int temp = 0;
	for (int i = 0; i < N - K + 1; i++){
		temp = abs(H[i + K - 1] - H[i]);
		
		result = min(result, temp);
	}
	
	cout << result << "\n";
	
}

