#include <bits/stdc++.h>

using namespace std;

bool mappa(int x, int y, vector<vector<char> >& map, vector<vector<bool> >& visited){
	
	
	visited[y][x] = true;
	
	
	cout << x << " " << y << " " << map[y][x] << " -> ";
	
	char hash = '#';
	char est = '@';
	
	bool has_est = false;
	
	if (map[y][x] == est){
		has_est = true;
	}
	
	
	bool a, b, c, d;
	
	// up, down, right, left
	if (!visited[y + 1][x]){
		if (map[y + 1][x] != hash){
			a = mappa(x, y + 1, map, visited);
		}
	}
	if (!visited[y - 1][x]){
		if (map[y - 1][x] != hash){
			b = mappa(x, y - 1, map, visited);
		}
	}
	if (!visited[y][x + 1]){
		if (map[y][x + 1] != hash){
			c = mappa(x + 1, y, map, visited);
		}
	}
	if (!visited[y][x - 1]){
		if (map[y][x - 1] != hash){
			d = mappa(x - 1, y, map, visited);
		}
	}
	
	
	cout << ((a || b || c || d) || has_est) << "\n";
	return (a || b || c || d) || has_est;
}

int main(){
	
	
	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);
	
//	ifstream cin("input.txt");
	ofstream outbrutto("output.txt");
	
	int R, C;
	
	cin >> R >> C;
	
	vector<vector<char> > map(R, vector<char>(C));
	
	for (int i = 0; i < R; i++){
		for (int j = 0; j < C; j++){
			cin >> map[i][j];
		}
	}
	
	
	vector<vector<bool> > visited(R, vector<bool>(C, false));
	
	bool tmp;
	
	int count = 0;
	
	char hash = '#';
	
	
	for (int i = 0; i < R; i++){
		for (int j = 0; j < C; j++){
			if (!visited[i][j] && map[i][j] != hash){
				
//				cout << "\n";
				
				cout << "prima: " << ""<< j << " " << i << "\n";
				tmp = mappa(j, i, map, visited);
				cout << " dopo: " << ""<< j << " " << i << " " << "" << "\n";
				cout << "tmp = " << tmp << "\n";
				if (!tmp){
					count++;
				}
			}
		}
	}
//	cout << "\n";
	
//	cout << mappa(7, 1, map, visited) << "\n";
	
	
	outbrutto << count << "\n";
	
	
	return 0;
}
