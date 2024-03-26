#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int N;
int query;
vector<bool> used;
vector<int> lampadine;
vector<vector<int>> gruppi;
vector<vector<int>> ans;

void study(int N);


vector<int> disconnect(vector<int> svitate) {
	query++;
	
	vector<int> query(N, 0);

	for (auto l: svitate) {
		if (l < 0 || l >= N) {
			cout << "Richiesta malformata. / Malformed query." << endl;
			exit(1);
		}
		if (query[l]) {
			cout << "Richiesta malformata. / Malformed query." << endl;
			exit(1);
		}
		query[l] = 1;
	}

	vector<int> ans(N, 1);
	for (int i = 0; i < N; i++) {
		if (query[i] && ans[i]) {
			for (auto l: gruppi[lampadine[i]]) {
				ans[l] = 0;
			}
		}
	}

	return ans;
}

void series(vector<int> lampadine) {
	if (lampadine.empty()) {
		cout << "Serie malformata. / Malformed series." << endl;
		exit(1);
	}

	for (auto lampadina: lampadine) {
		if (used[lampadina]) {
			cout << "Serie malformata. / Malformed series." << endl;
			exit(1);
		}
		used[lampadina] = true;
	}

	ans.push_back(lampadine);
}

int main() {
	// decommenta queste due righe per leggere da / scrivere su file
	// uncomment these two lines to read from / write to file
	// assert(freopen("input.txt", "r", stdin));
	// assert(freopen("output.txt", "w", stdout));

	cin >> N;

	lampadine.resize(N);
	used.resize(N);
	for (auto &l: lampadine) cin >> l;

	gruppi.resize(1 + *max_element(lampadine.begin(), lampadine.end()));
	for (int i = 0; i < N; i++) {
		gruppi[lampadine[i]].push_back(i);
	}

	study(N);

	cout << query << endl;
	cout << ans.size() << endl;
	for (auto group: ans) {
		cout << group.size() << " ";
		for (auto elem: group) {
			cout << elem << " ";
		}
		cout << endl;
	}
}
