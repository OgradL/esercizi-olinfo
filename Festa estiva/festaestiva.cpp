#include <bits/stdc++.h>

using namespace std;

int organizza(int N, int X, int Y, vector<int> A, vector<int> B){
	
	map<int, int> events;
	
	
	for (int i = 0; i < N; i++){
		if (A[i] > Y || B[i] < X) continue;
		events[A[i] < X ? X : A[i]]++;
		if (B[i] + 1 <= Y) events[B[i]+1]--;
	}
	
	events[X] += 0;
	events[Y] += 0;
	
	int ans = INT_MAX;
	int count = 0;
	
	for (auto it = events.begin(); it != events.end(); it++){
		count += it->second;
		
		ans = min(ans, count);
	}
	
	return N - ans;
}

int main(){
	
	int N, X, Y;
	
	cin >> N >> X >> Y;
	
	vector<int> A(N), B(N);
	
	for (int i = 0; i < N; i++){
		cin >> A[i] >> B[i];
	}
	
	cout << organizza(N, X, Y, A, B) << "\n";
	
	return 0;
}
