#include <iostream>
#include <vector>
#include <queue>
using namespace std;

using pll = pair<long long, int>;

int main(){

	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int N, M;
	cin >> N >> M;

	vector<vector<pair<int, long long>>> adj(N);
	long long a, b, w;
	for (int i = 0; i < M; i++){
		cin >> a >> b >> w;
		--a, --b;

		adj[a].push_back({b, w});
		adj[b].push_back({a, w});
	}

	vector<long long> dist(N, 1e18);
	dist[N-1] = 0;

	priority_queue<pll, vector<pll>, greater<pll>> pq;
	pq.push({0, N-1});

	vector<int> next(N, -1);
	vector<long long> length(N, -1);

	length[N-1] = 0;

	int best = N-1;
	while (!pq.empty()){
		auto [d, n] = pq.top();
		pq.pop();

		if (d > dist[n])
			continue;

		for (auto [x, w] : adj[n]){
			if (dist[x] > dist[n] + w){
				dist[x] = dist[n] + w;
				pq.push({dist[x], x});
			}

			if (dist[x] < dist[n] && length[n] < length[x] + w){
				length[n] = length[x] + w;
				next[n] = x;

				if (length[n] > length[best]){
					best = n;
				}
			}
		}
	}

	long long ans = length[best];

	vector<int> path(1, best);
	while (next[best] != -1){
		best = next[best];
		path.push_back(best);
	}

	cout << ans << " " << path.size() << "\n";
	for (int x : path){
		cout << x+1 << " ";
	}
	cout << "\n";

	return 0;
}
