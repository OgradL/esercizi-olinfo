#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

struct pers{
	long long p, f;

	bool operator<(const pers& a) const{
		if (f == a.f) return p > a.p;
		return f < a.f;
	}
};

long long bfs(int N, long long K, vector<int> P, vector<int> F){

	vector<pers> p(N);
	for (int i = 0; i < N; i++){
		p[i] = (pers){P[i], F[i]};
	}

	sort(p.begin(), p.end(), [](pers& a, pers& b){
		return a.p > b.p;
	});
	
	priority_queue<pers> pq;
	long long ans = 0, count = 0, prezzo = 1e9, spesa = 0;
	for (int i = 0; i < N; i++){
		prezzo = min(prezzo, p[i].p);
		count++;
		spesa += p[i].f;
		pq.push(p[i]);
		while (!pq.empty() && (pq.top().f > prezzo || spesa > K)){
			spesa -= pq.top().f;
			count--;
			pq.pop();
		}
		ans = max(ans, prezzo * count - spesa);
	}

	return ans;
}
