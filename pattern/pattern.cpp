#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

int main(){

	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int S;
	cin >> S;

	struct seg{
		int x1, y1, x2, y2;
	};

	vector<seg> pattern(S);
	for (auto& [x1, y1, x2, y2] : pattern){
		cin >> x1 >> y1 >> x2 >> y2;
	}

	int dx = pattern[0].x1;
	int dy = pattern[0].y1;
	for (auto& [x1, y1, x2, y2] : pattern){
		x1 -= dx;
		y1 -= dy;
		x2 -= dx;
		y2 -= dy;
	}

	int N;
	cin >> N;

	unordered_map<int, unordered_map<int, unordered_map<int, unordered_map<int, int>>>> m;
	vector<pair<int, int>> pos;
	vector<seg> drawing(N);
	for (auto& [x1, y1, x2, y2] : drawing){
		cin >> x1 >> y1 >> x2 >> y2;

		if (!m[x1].count(y1))
			pos.push_back({x1, y1});
		if (!m[x2].count(y2))
			pos.push_back({x2, y2});

		m[x1][y1][x2][y2]++;
		m[x2][y2][x1][y1]++;
	}


	int cnt = 0;
	for (auto [dx, dy] : pos){
		int ok = 1;
		for (auto& [x1, y1, x2, y2] : pattern){
			ok &= m[x1+dx][y1+dy][x2+dx][y2+dy];
			if (!ok)
				break;
		}

		if (ok)
			cnt++;
	}

	cout << cnt << "\n";

	return 0;
}
