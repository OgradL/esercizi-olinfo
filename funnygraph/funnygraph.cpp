#include <iostream>
#include <vector>
using namespace std;

struct DSU2{
	vector<pair<long long, long long>> parent;
	vector<long long> sizes;
	DSU2(int N){
		parent.assign(N+1, {0, 0});
		for (int i = 0; i <= N; i++)
			parent[i] = {i, 0};
		sizes.assign(N+1, 1);
	}
	pair<long long, long long> find_parent(int v){
		if (parent[v].first == v) return parent[v];
		pair<long long, long long> p = find_parent(parent[v].first);
		parent[v] = {p.first, p.second + parent[v].second};
		return parent[v];
	}
	int onion_set(int a, int b, long long z = 0){
		auto pa = find_parent(a);
		auto pb = find_parent(b);
		if (pa.first != pb.first){
			if (sizes[pa.first] < sizes[pb.first])
				swap(pa, pb), swap(a, b), z = -z;
			parent[pb.first] = {pa.first, pa.second - pb.second - z};
			sizes[pa.first] += sizes[pb.first];
			return 1;
		}
		return 0;
	}
};

int main(){

	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int N, M;
	cin >> N >> M;

	DSU2 dsu(N);
	int ans = M;
	int a, b, z;
	for (int i = 0; i < M; i++){
		cin >> a >> b >> z;

		if (!dsu.onion_set(a, b, z)){
			auto pa = dsu.find_parent(a);
			auto pb = dsu.find_parent(b);
			if (pa.second - pb.second != z){
				ans = min(ans, i);
			}
		}
	}

	cout << ans << "\n";

	return 0;
}
