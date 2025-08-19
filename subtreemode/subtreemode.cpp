#include <algorithm>
#include <tuple>
#include <vector>
using namespace std;

int N;
vector<int> ans, A;
vector<vector<int>> adj;
vector<vector<int>> freq_stack;
vector<int> subtree;

int subtree_size(int u){
	subtree[u] = 1;
	if (adj[u].empty())
		return 1;

	int best = adj[u][0];
	for (int x : adj[u]){
		int d = subtree_size(x);
		subtree[u] += d;
		if (subtree[best] < d)
			best = x;
	}

	int idx = 0;
	for (idx = 0; idx < adj[u].size(); idx++){
		if (adj[u][idx] == best)
			break;
	}

	swap(adj[u][0], adj[u][idx]);
	return subtree[u];
}

tuple<vector<int>, vector<int>, int> dfs(int u){
	vector<int> colors;
	vector<int> freq;

	colors.push_back(A[u]);
	int best = A[u];

	for (int x : adj[u]){
		auto [other_colors, other_freq, other_best] = dfs(x);

		if (colors.size() < other_colors.size() || freq.empty())
			swap(colors, other_colors), swap(freq, other_freq), swap(best, other_best);

		for (auto color : other_colors){
			if (freq[color] == 0)
				colors.push_back(color);

			if (other_freq.empty()){
				freq[color]++;
			} else {
				freq[color] += other_freq[color];
				other_freq[color] = 0;
			}

			if ((freq[color] == freq[best] && color < best) || freq[color] > freq[best])
				best = color;
		}

		if (!other_freq.empty()){
			freq_stack.push_back(std::move(other_freq));
		}
	}

	if (freq.empty()){
		freq = std::move(freq_stack.back());
		freq_stack.pop_back();
		freq[A[u]]++;
	}

	ans[u] = best;
	return {std::move(colors), std::move(freq), best};
}

vector<int> solve(int n, vector<int> p, vector<int> a){

	N = n;
	A = a;
	ans.resize(n);
	adj.resize(n);
	for (int i = 1; i < n; i++){
		adj[p[i]].push_back(i);
	}

	subtree.assign(N, 0);
	subtree_size(0);

	freq_stack.assign(20, vector<int>(N, 0));
	dfs(0);

	return ans;
}
