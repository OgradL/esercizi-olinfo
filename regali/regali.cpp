#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

int main(){

	// freopen("input.txt", "r", stdin);
	// freopen("output.txt", "w", stdout);

	int N, Q;

	cin >> N >> Q;

	vector<vector<int>> G(N, vector<int>(Q, 0));

	int n;
	for (auto &v : G){
		for (auto &n : v){
			cin >> n;
		}
	}

	int ans = 0;
	unordered_map<string, int> m;
	vector<int> pres(N, 1);
	vector<string> prefix(N, "");
	for (int i = 0; i < Q; i++){
		for (int j = 0; j < N; j++){
			if (!pres[j]) continue;
			prefix[j] += to_string(G[j][i]);
			
			m[prefix[j]]++;
		}

		for (int j = 0; j < N; j++){
			if (!pres[j]) continue;
			
			if (m[prefix[j]] <= 1) pres[j] = 0;
			else {
				ans = i+1;
			}
		}
		m.clear();
	}

	cout << ans << "\n";

	return 0;
}