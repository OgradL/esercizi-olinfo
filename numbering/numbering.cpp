#include <iostream>
#include <vector>
#include <variant>
#include "grader.cpp"
using namespace std;

variant<bool, vector<pair<int, int>>> find_numbering(int N, vector<int> A){
	vector<pair<int, int>> edges;
	bool sol_exists = true;

	vector<int> count(N);
	vector<vector<int>> nodes(N);
	long long sum = 0;
	for (int i = 0; i < N; i++)
		count[A[i]]++, nodes[A[i]].push_back(i), sum += A[i];
	
	for (int i = 0; i < N; i++)
		if (count[i] & 1)
			sol_exists = false;
	
	if (sum >= N * 2)
		sol_exists = false;
	
	if (!sol_exists)
		return false;

	vector<int> to_connect;
	int idx, free, prev_size, curr_size;
	for (int i = N-1; i > 0; i--){
		if (!count[i]) continue;
		if (count[i] < to_connect.size()){
			// trash
		} else {
			free = count[i] - to_connect.size();
			for (int j = 0; j < count[i] - free; j++){
				edges.push_back({nodes[i][j], to_connect[j]});
			}
			prev_size = to_connect.size();
			for (int n : nodes[i]){
				to_connect.push_back(n);
			}
			curr_size = to_connect.size();
			idx = curr_size - free + 1;
			for (int j = count[i] - free; j < count[i]; j += 2){
				edges.push_back({nodes[i][j], to_connect[idx]});
				idx = curr_size - free + ((idx - (curr_size - free) + 1) % free);
			}
		}
	}

	return edges;
}
