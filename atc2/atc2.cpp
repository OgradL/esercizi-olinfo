#include <iostream>
#include <vector>
using namespace std;

int dist(const pair<int, int>& a, const pair<int, int>& b){
	int dx = a.first - b.first;
	int dy = a.second - b.second;
	return dx * dx + dy * dy;
}

int main(){

	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int N;
	cin >> N;

	vector<pair<int, int>> towers;

	string s;
	for (int j = 0; j < N; j++){
		cin >> s;
		for (int i = 0; i < N; i++){
			if (s[i] == 'T') towers.emplace_back(i, j);
		}
	}

	N = towers.size();
	vector<int> mindist(N, 1e9);
	vector<int> visited(N, 0);
	int closest = 0;
	mindist[0] = 0;
	long long ans = 0;

	while (closest != -1){
		ans += mindist[closest];
		visited[closest] = 1;
		for (int i = 0; i < N; i++){
			if (!visited[i])
				mindist[i] = min(mindist[i], dist(towers[i], towers[closest]));
		}

		closest = -1;
		for (int i = 0; i < N; i++){
			if (!visited[i] && (closest == -1 || mindist[i] < mindist[closest]))
				closest = i;
		}
	}

	cout << ans << "\n";

	return 0;
}
