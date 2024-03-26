#include <iostream>
#include <vector>
#include <queue>
using namespace std;

template<class T>
void operator>>(istream& cin, vector<T>& v){
	for (T& x : v)
		cin >> x;
}

#define UL 0
#define UR 1
#define DR 2
#define DL 3


int main(){

	int N, M;
	cin >> N >> M;

	vector<vector<int>> m(M, vector<int>(N));
	for (int i = 0; i < N; i++){
		for (int j = 0; j < M; j++){
			cin >> m[j][i];
		}
	}


	int ans = -1;
	queue<pair<pair<int, int>, pair<int, int>>> q;
	q.push({{0, 0}, {0, 1}});
	vector<vector<vector<int>>> v(M, vector<vector<int>>(N, vector<int>(4, 0)));
	pair<pair<int, int>, pair<int, int>> n;
	int x, y, d, di;
	while (!q.empty()){
		n = q.front();
		q.pop();
		x = n.first.first;
		y = n.first.second;
		d = n.second.first;
		di = n.second.second;

		if (x < 0 || x >= M)
			continue;
		if (y < 0 || y >= N)
			continue;

		if (x == M-1 && y == N-1){
			ans = di;
			break;
		}

		if (v[x][y][d])
			continue;

		v[x][y][d] = 1;

		// cout << x << " " << y << " " << d << " " << di << " -" << m[x][y] << " (" << (m[x][y] & (1<<0)) << " " << (m[x][y] & (1<<1)) << " " << (m[x][y] & (1<<2)) << " " << (m[x][y] & (1<<3)) << ")\n";


		if (d == UL){
			q.push({{x-1, y}, {UR, di+1}});
			q.push({{x, y-1}, {DL, di+1}});
			q.push({{x-1, y-1}, {DR, di+1}});
			if (!(m[x][y] & (1<<0)))
				q.push({{x, y}, {UR, di}});
			if (!(m[x][y] & (1<<3)))
				q.push({{x, y}, {DL, di}});
		}
		if (d == UR){
			q.push({{x+1, y}, {UL, di+1}});
			q.push({{x, y-1}, {DR, di+1}});
			q.push({{x+1, y-1}, {DL, di+1}});
			if (!(m[x][y] & (1<<0)))
				q.push({{x, y}, {UL, di}});
			if (!(m[x][y] & (1<<1)))
				q.push({{x, y}, {DR, di}});
		}
		if (d == DR){
			q.push({{x+1, y}, {DL, di+1}});
			q.push({{x, y+1}, {UR, di+1}});
			q.push({{x+1, y+1}, {UL, di+1}});
			if (!(m[x][y] & (1<<2)))
				q.push({{x, y}, {DL, di}});
			if (!(m[x][y] & (1<<1)))
				q.push({{x, y}, {UR, di}});
		}
		if (d == DL){
			q.push({{x-1, y}, {DR, di+1}});
			q.push({{x, y+1}, {UL, di+1}});
			q.push({{x-1, y+1}, {UR, di+1}});
			if (!(m[x][y] & (1<<2)))
				q.push({{x, y}, {DR, di}});
			if (!(m[x][y] & (1<<3)))
				q.push({{x, y}, {UL, di}});
		}
	}

	cout << ans << "\n";

	return 0;
}