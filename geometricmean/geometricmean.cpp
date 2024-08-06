#include <iostream>
#include <vector>
using namespace std;

const int MAXN = 1000042;

int main(){

	int N;
	cin >> N;

	vector<int> V(N);
	for (int& x : V)
		cin >> x;

	vector<vector<pair<int, int>>> factors(MAXN);
	for (int i = 2; i < MAXN; i++){
		int count = 1;
		if (factors[i].size() == 0){
			for (int j = i; j < MAXN; j++){
				if (count)
					factors[j].push_back({i, count++});
				count %= 4;
			}
		}
	}


	vector<vector<pair<int, int>>> LISTA;

	auto join = [&](const vector<pair<int, int>>& a, const vector<pair<int, int>>& b){
		vector<pair<int, int>> res;
		int i = 0, j = 0;
		while (i < a.size() || j < b.size()){
			if (i == a.size()){
				res.push_back(b[j++]);
			} else if (j == b.size()){
				res.push_back(a[i++]);
			} else if (a[i].first < b[j].first){
				res.push_back(a[i++]);
			} else if (a[i].first > b[j].first){
				res.push_back(b[j++]);
			} else {
				int e = (a[i].second + b[j].second) % 4;
				if (e)
					res.push_back({a[i].first, e});
				i++, j++;
			}
		}
		return res;
	};

	for (int i = 0; i < N; i++){
		for (int j = i+1; j < N; j++){
			LISTA.push_back(join(factors[V[i]], factors[V[j]]));
		}
	}

	return 0;
}
