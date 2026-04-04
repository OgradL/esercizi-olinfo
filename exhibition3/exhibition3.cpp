#include <functional>
#include <iostream>
#include <vector>
using namespace std;

int main(){

	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int N, M;
	cin >> N >> M;

	string S;
	cin >> S;

	vector<int> deg(N, 0);
	vector<vector<int>> adj(N), radj(N);
	for (int i = 0; i < M; i++){
		int a, b;
		cin >> a >> b;
		adj[a].push_back(b);
		radj[b].push_back(a);
		deg[a]++;
	}

	vector<int> loosing(N, 0);
	vector<int> seen(N, 0);

	function<int(int)> dfs = [&](int v) -> int {
		seen[v] = 1;

		int cyc = 0;
		for (int x : adj[v]){
			if (S[x] != 'C')
				continue;
			if (seen[x] == 1 || seen[x] == 3){
				cyc = 1;
				break;
			}
			cyc |= dfs(x);
		}

		if (cyc){
			loosing[v] = 1;
			seen[v] = 3;
		} else {
			seen[v] = 2;
		}

		return cyc;
	};

	function<void(int)> dfs2 = [&](int v) -> void {
		if (seen[v] == 4)
			return;
		seen[v] = 4;
		loosing[v] = 1;

		for (int x : radj[v]){
			deg[x]--;
			if ((deg[x] == 0 && seen[x] < 3) || (S[x] == 'C' && seen[x] < 3)){
				dfs2(x);
			}
		}
	};

	for (int i = 0; i < N; i++){
		if (seen[i] == 0 && S[i] == 'C'){
			dfs(i);
		}
	}

	for (int i = 0; i < N; i++){
		if (deg[i] == 0 || seen[i] == 3){
			dfs2(i);
		}
	}


	for (int x : loosing){
		cout << 1 - x;
	}
	cout << "\n";

	return 0;
}
