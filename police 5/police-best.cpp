#include <iostream>
#include <vector>
#include <queue>
using namespace std;

struct arco{
	int a, b, c, e;
};

int main(){

	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	int N, M, T;
	cin >> N >> M >> T;

	vector<vector<arco>> G(N);
	int a, b, c, e;
	for (int i = 0; i < M; i++){
		cin >> a >> b >> c >> e;
		G[a].push_back((arco){a, b, c, e});
	}

	vector<int> dist(N, 1e9);

	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
	pq.push({0, 0});
	dist[0] = 0;

	int nodo, d;
	pair<int, int> n;
	while (!pq.empty()){
		n = pq.top();
		pq.pop();

		d = n.first;
		nodo = n.second;

		if (nodo == N-1)
			break;

		if (d > dist[nodo])
			continue;

		for (arco x : G[nodo]){
			if (d + x.c < dist[x.b] && !(d + x.c > T && x.e)){
				dist[x.b] = d + x.c;
				pq.push({d + x.c, x.b});
			}
		}
	}

	cout << ((nodo == N-1) ? d : -1) << "\n";

	return 0;
}