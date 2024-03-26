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

	vector<vector<int>> g(1);
	g[0].resize(N);
	for (int i = 0; i < N; i++)
		g[0][i] = i;

	int n_groups = 1, t = 300;

	vector<int> L, query;
	while (t--){
		L.resize(0);
		for (int i = 0; i < n_groups; i++){
			shuffle(g[i].begin(), g[i].end(), generator);
			int s = (sqrt(g[i].size()) + 1) / 2;

			for (int j = 0; j < s && j < g[i].size(); j++){
				L.push_back(g[i][j]);
			}
		}
		query = disconnect(L);


		vector<int> v(n_groups, 0);
		for (int i = 0; i < n_groups; i++){
			for (int j = 0; j < g[i].size(); j++){
				if (!query[g[i][j]]){
					if (!v[i])
						g.push_back(vector<int>()), v[i] = 1;
					g.back().push_back(g[i][j]);
					g[i].erase(g[i].begin() + j);
					j--;
				}
			}
		}
		
		for (int i = 0; i < g.size(); i++){
			if (g[i].size() == 0)
				g.erase(g.begin() + i);
		}
		n_groups = g.size();
	}

	for (auto x : g)
		if (x.size() != 0)
			series(x);

}
