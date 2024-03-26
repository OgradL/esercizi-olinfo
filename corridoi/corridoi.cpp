#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

struct point{
	long long n1, n2;
	bool operator<(const point& a) const {
		if ((n1 * 2 + n2) == (a.n1 * 2 + a.n2))
			return n1 > n2;
		return (n1 * 2 + n2) > (a.n1 * 2 + a.n2);
	}
};

vector<long long> dijkstra(int N, int M, int root, vector<vector<pair<int, long long>>>& G){
	vector<long long> dist(N, 1e18), ans(N, -1);
	dist[root] = 0;
	priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<pair<long long, int>>> pq;
	pq.push({0, root});
	while (!pq.empty()){
		auto [d, n] = pq.top();
		pq.pop();
		

		if (dist[n] > d)
			continue;
		
		if (ans[n] != -1)
			continue;
		
		ans[n] = d;
		
		for (auto [x, c] : G[n]){
			if (dist[x] > dist[n] + c){
				dist[x] = dist[n] + c;
				pq.push({dist[x], x});
			}
		}
	}
	return ans;
}

vector<long long> shorten(int N, int M, int Q, vector<long long> K, vector<int> A, vector<int> B, vector<int> C){

	vector<vector<pair<int, long long>>> G(N);
	for (int i = 0; i < M; i++){
		G[A[i]].push_back({B[i], C[i]});
		G[B[i]].push_back({A[i], C[i]});
	}

	vector<long long> d0, d1, d2;
	d0 = dijkstra(N, M, 0, G);
	d1 = dijkstra(N, M, 1, G);
	d2 = dijkstra(N, M, 2, G);

	vector<int> queries(Q);
	for (int i = 0; i < Q; i++)
		queries[i] = i;
	
	sort(queries.begin(), queries.end(), [&](int a, int b){
		return K[a] < K[b];
	});

	priority_queue<point> s1, s2;

	for (int i = 0; i < N; i++){
		s1.push((point){d1[i], d0[i] + d2[i]});
	}

	vector<long long> answer(Q, 0);

	long long k;
	for (int idx : queries){
		k = K[idx];
		while (!s1.empty() && s1.top().n1 < K[idx]){
			auto t = s1.top();
			s2.push((point){0, t.n1 + t.n2});
			s1.pop();
		}

		point b1 = (point){1LL<<60, 1LL<<60};
		if (!s1.empty())
			b1 = s1.top();

		point b2 = (point){1LL<<60, 1LL<<60};
		if (!s2.empty())
			b2 = s2.top();
		
		answer[idx] = max(0LL, min(
			(b1.n1 - k) * 2 + b1.n2,
			b2.n2 - k
		));
	}

	return answer;
}