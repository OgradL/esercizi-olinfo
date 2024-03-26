#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

int calc_depth(int n, vector<int>& depth, vector<int>& M){
	if (depth[n] != -1) return depth[n];
	return depth[n] = calc_depth(M[n], depth, M) + 1;
}

int main(){

	// freopen("input.txt", "r", stdin);
	// freopen("output.txt", "w", stdout);

	int N, E;
	cin >> N >> E;

	vector<int> M(N + E, -1);
	for (int i = 0; i < N; i++){
		cin >> M[i];
	}

	vector<int> depth(N+E, -1);
	vector<int> dps(102, 0);
	depth[0] = 0;
	int tree_depth = 0;
	for (int i = 0; i < N; i++){
		depth[i] = calc_depth(i, depth, M);
		tree_depth = max(tree_depth, depth[i]);
		dps[depth[i]]++;
	}

	int new_depth, cyclic = 0;
	int new_node = N;
	int C, K;
	vector<int> S;
	while (E-- && !cyclic){
		cin >> C >> K;
		S.resize(K);
		for (int &n : S)
			cin >> n;
		
		M[new_node] = C;
		new_depth = depth[C] + 1;
		depth[new_node] = depth[C] + 1;
		dps[depth[new_node]]++;
		for (int i = 0; i < K; i++){
			M[S[i]] = new_node;
			dps[depth[S[i]]]--;
			depth[S[i]] = depth[new_node] + 1;
			dps[depth[S[i]]]++;
			new_depth = max(new_depth, depth[S[i]]);
		}
		new_node++;

		unordered_map<int, int> v;
		v[C] = 1;
		int n = C;
		while (M[n] != -1 && !cyclic){
			n = M[n];
			if (v[n])
				cyclic = 1;
			v[n] = 1;
		}

		int lo = 0, hi = 101, mid;
		while (lo + 1 < hi){
			mid = (lo + hi) / 2;
			if (dps[mid])
				lo = mid;
			else
				hi = mid;
		}
		new_depth = lo;

		if (cyclic){
			cout << "c";
			break;
		} else if (new_depth > tree_depth){
			cout << "1";
		} else {
			cout << "0";
		}
		tree_depth = new_depth;
		// if (!dps[tree_depth])
			// tree_depth--;
	}

	cout << endl;

	return 0;
}