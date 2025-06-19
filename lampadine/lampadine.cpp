#include <vector>
using namespace std;

vector<int> disconnect(vector<int> L);
void series(vector<int> G);

void study(int N) {

	vector<pair<vector<int>, int>> groups, new_groups;

	groups.push_back({{}, N});
	for (int i = 0; i < N; i++){
		groups.back().first.push_back(i);
	}
	
	while (!groups.empty()){
		new_groups.clear();

		vector<int> to_query;

		for (auto& [g, maxg] : groups){
			maxg = min(maxg, (int)g.size());

			if (maxg <= 1){
				if (maxg == 1)
					series(g);
				continue;
			}

			for (int i = 0; i < maxg/2; i++){
				to_query.push_back(g[i]);
			}
		}

		if (to_query.empty())
			break;

		vector<int> query = disconnect(to_query);

		for (auto& [g, maxg] : groups){
			if (maxg <= 1){
				continue;
			}

			vector<int> g1, g2;

			for (int x : g){
				if (query[x])
					g1.push_back(x);
				else
					g2.push_back(x);
			}

			new_groups.push_back({g1, (maxg+1)/2});
			new_groups.push_back({g2, maxg/2});
		}

		swap(groups, new_groups);
	}
}
