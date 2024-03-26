#include <iostream>
#include <queue>
using namespace std;

#define type second
#define time first


int main(int argc, char** argv){

	if (argc > 1){
		freopen(argv[1], "r", stdin);
	}

	int T, N, M, a, b;
	cin >> T;

	vector<pair<int, int>> A, B;

	cin >> N;
	for (int i = 0; i < N; i++){
		cin >> a >> b;
		A.push_back({a, b});
	}
	cin >> M;
	for (int j = 0; j < M; j++){
		cin >> a >> b;
		B.push_back({a, b});
	}

	int ans = 0;
	int t = 0, i = 0, j = 0, last_together = -1;
	while (i < N && j < M){
		if (A[i].second < t) i++;
		if (B[j].second < t) j++;
		if (
			A[i].first <= t && t <= A[i].second &&
			B[j].first <= t && t <= B[j].second
			){
				ans++;
				last_together = t;
				// cout << "together at " << t << "\n";
			}
		
		if (
			A[i].first <= t && t <= A[i].second &&
			last_together - t > T
			){
				i++;
			}

		t++;
	}


	cout << ans << "\n";

	return 0;
}