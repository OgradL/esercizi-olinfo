#include <iostream>
#include <vector>
using namespace std;

vector<vector<string>> tiling(int N){

	vector<vector<string>> ans;

	auto rec = [&](auto&& rec, int x, int y, vector<pair<int, int>>& points) -> void {
		if (x + y == 2*N-1){
			vector<string> sol1(21, string(21, '.'));
			vector<string> sol2(21, string(21, '.'));

			for (int k = 0; k < 7; k++){
				for (auto [px, py] : points){
					sol1[px+k][7+py-k] = 'A' + k;
					sol2[px+k][14-py+k] = 'A' + k;
				}
			}

			if (x)
				ans.push_back(sol1);

			if (y)
				ans.push_back(sol2);

			return;
		}


		for (int k = 0; k < 2; k++){
			points.push_back({x+1-k, y+k});
			rec(rec, x+1-k, y+k, points);
			points.pop_back();
		}
	};

	vector<pair<int, int>> e;
	e.push_back({0, 0});

	rec(rec, 0, 0, e);

	if (ans.size() > 16000)
		ans.resize(16000);

	return ans;
}

int main(){

	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int N;
	cin >> N;

	vector<vector<string>> res = tiling(N);

	cout << res.size() << "\n";
	for (auto m : res){
		cout << m.size() << " " << m[0].size() << "\n";
		for (auto y : m){
			cout << y << "\n";
		}
	}

	return 0;
}
