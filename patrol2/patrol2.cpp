#include <iostream>
#include <vector>
#include <queue>
using namespace std;

struct nodo{
	long long to, dist;
	bool operator<(const nodo& a) const{
		return a.dist < dist;
	}
};

int main() {
	
	int N, M, L;
	cin >> N >> M >> L;
	
	vector<vector<int>> G(N, vector<int>(0));
	
	int a, b;
	for (int i = 0; i < M; i++){
		cin >> a >> b;
		G[a].push_back(b);
		G[b].push_back(a);
	}
	
	vector<int> C(L);
	for (int &n : C)
		cin >> n;
	
	priority_queue<nodo> pq;
	vector<long long> dis(N, 1e18);
	
	pq.push((nodo){0, 1});
	
	nodo n;
	while (!pq.empty()){
		n = pq.top();
		pq.pop();
		
		if (n.to == N - 1) break;
		if (n.to == C[n.dist % L]) continue;
		
		for (int x : G[n.to]){
			if (dis[x] > n.dist + 1 && x != C[(n.dist+1)%L]){
				dis[x] = n.dist + 1;
				pq.push((nodo){x, dis[x]});
			}
		}

		if (n.to != C[(n.dist+1)%L] && n.dist <= dis[n.to] + 1){
			pq.push((nodo){n.to, n.dist + 1});
		}
	}
	
	cout << n.dist << "\n";
	
	return 0;
}