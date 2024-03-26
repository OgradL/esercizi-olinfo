#include <bits/stdc++.h>

using namespace std;



int main(){
	
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);
	
	int N, M, H, S;
	
	cin >> N >> M >> H >> S;
	
	pair<int, int> start;
	start.first = start.second = 500000;
	
	
	vector<pair<int, int> > nodes(N, start);
	
	
	for (int i = 0; i < M; i++){
		int A, B, L;
		
		cin >> A >> B >> L;
		
		if (nodes[A - 1].second > L){
			pair<int, int> paio;
			paio.first = B - 1;
			paio.second = L;
			nodes[A - 1] = paio;
		}
		
		if (nodes[B - 1].second > L){
			pair<int, int> paio;
			paio.first = A - 1;
			paio.second = L;
			nodes[B - 1] = paio;
		}
		
		
	}
	
//	cout << "\n";
	
//	for (int i = 0; i < N; i++){
//		cout << i << " " << nodes[i].first << " " << nodes[i].second << "\n";
//	}
	
	int moves = 0;
	
	int current = H - 1;
	
//	cout << "\n\n\n";
	while (moves <= 50000 && current != S - 1){
		current = nodes[current].first;
		moves++;
	}
	
	if (moves == 50001) moves = -1;
	
	cout << moves << "\n";
	
	return 0;
}
