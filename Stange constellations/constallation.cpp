#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

#define MAXCOORD 200000

int main(){
	
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);
	
	cin.tie(0);
	cin.sync_with_stdio(false);

	int N;
	
	cin >> N;
	
	unordered_map<int, int> X;
	unordered_map<int, int> Y;
	
	vector<pair<int, int>> stars(N);
	
	int A, B;
	for (int i = 0; i < N; i++){
		cin >> A >> B;
		X[A]++;
		Y[B]++;
		stars[i] = make_pair(A, B);
	}
	
	long long ans = 0;
	
	for (int i = 0; i < N; i++){
		ans += (X[stars[i].first] - 1) * (Y[stars[i].second] - 1);
	}
	
	cout << ans << "\n";
	
	return 0;
}