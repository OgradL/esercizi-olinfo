#include <iostream>
#include <vector>
#include <queue>
using namespace std;

struct node{
	int n;
	int dist;
	int cs[2];
};

int main(){

	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int N, M;
	cin >> N >> M;

	vector<vector<int>> colors(N);
	
	vector<int> C(N);
	for (int i = 0; i < N; i++){
		cin >> C[i];
		colors[C[i]].push_back(i);
	}
	
	vector<vector<int>> G(N);
	int a, b;
	for (int i = 0; i < M; i++){
		cin >> a >> b;
		G[a].push_back(b);
		G[b].push_back(a);
	}

	int ans = 1e9;

	vector<int> seen(N, -1);

	for (int c = 0; c < N; c++){
		queue<node> q;
		for (int n : colors[c]){
			seen[n] = c;
			q.push((node){n, 0, {c, -1}});
		}
		int quit = 0;
		while (!q.empty() && !quit){
			auto [n, d, cs] = q.front();
			q.pop();

			if (C[n] != cs[0] && C[n] != cs[1] && cs[1] != -1){
				ans = min(ans, d);
				break;
			}

			if (C[n] != cs[0])
				cs[1] = C[n];

			for (int x : G[n]){
				if (C[x] != cs[0] && C[x] != cs[1] && cs[1] != -1){
					ans = min(ans, d+1);
					quit = 1;
					break;
				}
				if (seen[x] < cs[0]){
					seen[x] = cs[0];
					q.push((node){x, d + 1, {cs[0], cs[1]}});
				}
			}
		}
	}

	cout << (ans == 1e9 ? -1 : ans) << "\n";

	return 0;
}