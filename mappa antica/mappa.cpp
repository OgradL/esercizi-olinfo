#include <bits/stdc++.h>

using namespace std;

void mappa(int x, int y, int N, vector<vector<char> >& map, vector<vector<int> >& dist, int distance){
	
	dist[y][x] = distance;
	
	char ast = '*';
	
	// up, down, right, left
	if (y < N - 1){
		if (map[y + 1][x] == ast){
			if (dist[y + 1][x] > distance + 1){
				mappa(x, y + 1, N, map, dist, distance + 1);
			}
		}
	}
	if (y > 0){
		if (map[y - 1][x] == ast){
			if (dist[y - 1][x] > distance + 1){
				mappa(x, y - 1, N, map, dist, distance + 1);
			}
		}
	}
	if (x < N - 1){
		if (map[y][x + 1] == ast){
			if (dist[y][x + 1] > distance + 1){
				mappa(x + 1, y, N, map, dist, distance + 1);
			}
		}
	}
	if (x > 0){
		if (map[y][x - 1] == ast){
			if (dist[y][x - 1] > distance + 1){
				mappa(x - 1, y, N, map, dist, distance + 1);
			}
		}
	}
	
	// up-right, up-left, down-left, down-right
	
	if (x < N - 1 && y < N - 1){
		if (map[y + 1][x + 1] == ast){
			if (dist[y + 1][x + 1] > distance + 1){
				mappa(x + 1, y + 1, N, map, dist, distance + 1);
			}
		}
	}
	if (x < N - 1 && y > 0){
		if (map[y - 1][x + 1] == ast){
			if (dist[y - 1][x + 1] > distance + 1){
				mappa(x + 1, y - 1, N, map, dist, distance + 1);
			}
		}
	}
	if (x > 0 && y > 0){
		if (map[y - 1][x - 1] == ast){
			if (dist[y - 1][x - 1] > distance + 1){
				mappa(x - 1, y - 1, N, map, dist, distance + 1);
			}
		}
	}
	if (x > 0 && y < N - 1){
		if (map[y + 1][x - 1] == ast){
			if (dist[y + 1][x - 1] > distance + 1){
				mappa(x - 1, y + 1, N, map, dist, distance + 1);
			}
		}
	}
	
	
	
}

int main(){
	
	
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);
	
	int N;
	
	cin >> N;
	
	vector<vector<char> > map(N, vector<char>(N));
	
	for (int i = 0; i < N; i++){
		for (int j = 0; j < N; j++){
			cin >> map[i][j];
		}
	}
	
	vector<vector<int> > dist(N, vector<int>(N, 1e9));
	
	mappa(0, 0, N, map, dist, 0);
	
	cout << dist[N - 1][N - 1] + 1 << "\n";
	
	
	return 0;
}

