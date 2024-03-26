#include <iostream>
#include <vector>
#include <queue>
using namespace std;

struct comp{
	bool operator()(const pair<int, double>& a, const pair<int, double>& b) const {
		return (a.second != b.second) ? (a.second < b.second) : (a.first < b.first);
	}
};

int main(){

	int N, M;
	cin >> N >> M;

	vector<vector<pair<int, int>>> G(N);
	int a, b, c;
	for (int i = 0; i < M; i++){
		cin >> a >> b >> c;
		G[a].push_back({b, c});
	}

	pair<int, int> ans = {N, N};
	double anstax = 1000;
	for (int i = 0; i < N; i++){
		vector<double> tax(N, 0);
		priority_queue<pair<int, double>, vector<pair<int, double>>, comp> pq;
		pq.push({i, 1000});
		tax[i] = 1000;

		pair<int, double> n, best = {i, 1000};
		while (!pq.empty()){
			n = pq.top();
			pq.pop();

			if (n.second < tax[n.first])
				continue;

			for (auto x : G[n.first]){
				if (n.second * (1000-x.second)/1000.0 > tax[x.first]){
					tax[x.first] = n.second * (1000-x.second)/1000.0;
					pq.push({x.first, n.second * (1000-x.second)/1000.0});
				}
			}
			if (n.second < best.second){
				best = n;
			}
		}

		if (best.second < anstax){
			ans = {i, best.first};
			anstax = best.second;
		}
	}

	cout << ans.first << " " << ans.second << "\n";

	return 0;
}