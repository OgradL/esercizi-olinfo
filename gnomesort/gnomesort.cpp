#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
using namespace std;

struct DSU{
	int N;
	vector<int> par, sz;

	DSU(int N_){
		N = N_+1;
		par.assign(N, 0);
		for (int i = 0; i < N; i++)
			par[i] = i;
		sz.assign(N, 1);
	}

	int get_par(int x){
		if (x == par[x]) return x;
		return par[x] = get_par(par[x]);
	}

	void onion_set(int a, int b){
		a = get_par(a);
		b = get_par(b);
		if (a != b){
			if (sz[a] < sz[b])
				swap(a, b);
			sz[a] += sz[b];
			par[b] = a;
		}
	}
};

int main(){

	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int N;
	cin >> N;

	vector<int> V(N);
	for (int& x : V)
		cin >> x;
	
	vector<pair<int, int>> coppie;

	int ok = 1;
	for (int i = 0; i < N; i++){
		ok &= (V[V[i]] == i);
		if (V[i] != i){
			if (i < V[i])
				coppie.push_back({i, V[i]});
		}
	}

	cout << (ok ? "YES" : "NO") << "\n";

	if (!ok){
		return 0;
	}

	sort(coppie.begin(), coppie.end(), [&](const pair<int, int>& a, const pair<int, int>& b){
		if (a.first == b.first)
			return a.second < b.second;
		return a.first < b.first;
	});

	vector<int> events(N, 0);

	for (int i = 0; i < coppie.size(); i++){
		events[coppie[i].first] = i+1;
		events[coppie[i].second] = -i-1;
	}

	DSU dsu(coppie.size());

	vector<int> parent(coppie.size(), -1);
	vector<int> matched(coppie.size(), 0);
	set<int> pos;
	for (int i = 0; i < N; i++){
		if (events[i] == 0)
			continue;
		
		auto copp = coppie[abs(events[i])-1];
		if (events[i] > 0){
			pos.insert(copp.second);
			auto it = pos.lower_bound(copp.second+1);
			if (it == pos.end())
				continue;
			int idx = *it;

			matched[abs(events[idx])-1] = 1;
			dsu.onion_set(abs(events[i])-1, abs(events[idx])-1);
			pos.erase(it);
		} else {
			if (!matched[abs(events[i])-1]){
				pos.erase(copp.second);
			}
		}
	}
	
	vector<int> seen(coppie.size(), 0);
	int n_ops = 0;

	vector<vector<int>> ops(coppie.size());
	for (int i = 0; i < coppie.size(); i++){
		n_ops += seen[dsu.get_par(i)]++ == 0;
		ops[dsu.get_par(i)].push_back(coppie[i].first);
		ops[dsu.get_par(i)].push_back(coppie[i].second);
	}


	cout << n_ops << "\n";

	for (auto& x : ops){
		if (x.size() == 0)
			continue;
		cout << x.size() << " ";
		for (int& y : x)
			cout << y << " ";
		cout << "\n";
	}

	return 0;
}
