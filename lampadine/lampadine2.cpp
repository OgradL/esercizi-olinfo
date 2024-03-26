#include <iostream>
#include <vector>
#include <algorithm>
#include <random>
using namespace std;

vector<int> disconnect(vector<int> L);
void series(vector<int> G);

template<class T>
void operator<<(ostream& a, vector<T>& v){
	for (auto &x : v) cout << (x), cout << " ";
	cout << "\n";
}

void study(int N) {

	random_device dev;
	mt19937 generator(dev());

	vector<vector<int>> g(3*N), new_groups;
	g[0].resize(N);
	for (int i = 0; i < N; i++)
		g[0][i] = i;

	int n_groups = 1, t = 5;

	vector<int> L, query;
	while (t--){
		L.resize(0);
		for (int i = 0; i < n_groups; i++){
			shuffle(g[i].begin(), g[i].end(), generator);
			int s = (sqrt(g[i].size()) + 1) / 2;

			for (int j = 0; j < s; j++){
				L.push_back(g[i][j]);
			}
		}
		cout << "query: " << L;
		query = disconnect(L);
		cout << "ans: " << query;
		for (int i = 0; i < n_groups; i++){
			for (int j = 0; j < g[i].size(); j++){
				if (query[g[i][j]]){
					g[n_groups + 2*i].push_back(g[i][j]);
				} else {
					g[n_groups + 2*i+1].push_back(g[i][j]);
				}
			}
		}
		g.erase(g.begin(), g.begin() + n_groups);
		g.resize(3*N);
		// n_groups = find_if(g.begin(), g.end(), [](const vector<int>& a){
		// 	return a.size() == 0;
		// }) - g.begin();
		n_groups = 0;
		cout << "fine\n";
		for (int i = 0; i < g.size(); i++){
			if (g[i].size() != 0)
				cout << g[i], n_groups++;
			else
				g.erase(g.begin() + i);
		}
		cout << "\n\n";
	}

	for (int i = 0; i < n_groups; i++){
		series(g[i]);
	}

}
