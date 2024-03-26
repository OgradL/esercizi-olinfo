#include <iostream>
#include <vector>
#include <queue>
using namespace std;

#define UL 0
#define DL 1
#define UR 2
#define DR 3

#define U 0
#define D 1
#define L 0
#define R 2

#define V 1
#define O 2

int poo[] = {0, 2, 0, 2};
int pov[] = {3, 3, 1, 1};

int main(){

	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

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
	q.push({{0, 0}, {UL, 1}});
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

		if (x == M-1 && y == N-1 && d == DR){
			ans = di;
			break;
		}

		if (v[x][y][d])
			continue;

		v[x][y][d] = 1;

		// cout << x << " " << y << " " << d << " " << di << " -" << m[x][y] << " (v: " << !(m[x][y] & (1<<pov[d])) << " o: " << !(m[x][y] & (1<<poo[d])) << " - " << (m[x][y] & (1<<0)) << " " << (m[x][y] & (1<<1)) << " " << (m[x][y] & (1<<2)) << " " << (m[x][y] & (1<<3)) << ")\n";
		int dx = ((d & O) >> 1) * 2 - 1;
		int dy = (d & V) * 2 - 1;

		q.push({{x+dx, y}, {d ^ O, di+1}});
		q.push({{x, y+dy}, {d ^ V, di+1}});
		q.push({{x+dx, y+dy}, {d ^ O ^ V, di+1}});
		if (!(m[x][y] & (1<<poo[d])))
			q.push({{x, y}, {d ^ O, di}});
		if (!(m[x][y] & (1<<pov[d])))
			q.push({{x, y}, {d ^ V, di}});

		
	}

	cout << ans << "\n";

	return 0;
}