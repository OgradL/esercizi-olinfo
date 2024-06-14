#include <iostream>
#include <vector>
#include <queue>
#include <variant>
#include <functional>
using namespace std;

variant<bool, vector<int>> find_tour(int N, vector<int> A){

	deque<int> open;
	vector<vector<int>> G(N);

	auto add_edge = [&](int a, int b){
		G[a].push_back(b);
		G[b].push_back(a);
	};

	function<int(int, int)> dfs;
	dfs = [&](int n, int p){
		for (int x : G[n]){
			if (x == p) continue;
			return dfs(x, n);
		}
		return n;
	};

	vector<int> tour;
	tour.push_back(0);

	open.push_back(0);
	add_edge(0, N-1);

	for (int i = 1; i < N; i++){
		if ((int)open.size() <= 0)
			return false;
		if ((A[i] & 1) == 0){
			if (open.size() == A[i] - 3){
				open.push_back(i);
				open.push_back(i);
			} else if (open.size() == A[i] - 1){
				add_edge(open.front(), i);
				open.pop_front();
				if (i != N-1){
					add_edge(open.front(), i);
					open.pop_front();
				}
			} else {
				return false;
			}
		} else {
			if (open.size() == A[i] - 2){
				add_edge(open.front(), i);
				open.pop_front();
				open.push_back(i);
			} else {
				return false;
			}
		}
	}
	if (open.size() != 0)
		return false;
	
	vector<int> tour(N);
	int idx = 0, prev = N-1;
	for (int i = 0; i < N; i++){
		tour[i] = idx;
		if (G[idx][0] == prev)
			idx = G[idx][1];
		else
			idx = G[idx][0];
		prev = tour[i];
	}

	return tour;
}

