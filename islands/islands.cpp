#include <bits/stdc++.h>

using namespace std;

bool is_island(int x, int y, int R, int C, vector<vector<int> >& map, vector<vector<bool> >& visited){
	
	visited[y][x] = true;
	
	bool a = true, b = true, c = true, d = true;
	
	if (x > 0){
		if (map[y][x - 1] == 1){
			if (!visited[y][x - 1]){
				if (!is_island(x - 1, y, R, C, map, visited)){
					a = false;
				}
			}
		}
	} else a = false;
	if (x < C - 1){
		if (map[y][x + 1] == 1){
			if (!visited[y][x + 1]){
				if (!is_island(x + 1, y, R, C, map, visited)){
					b = false;
				}
			}
		}
	} else b = false;
	if (y > 0){
		if (map[y - 1][x] == 1){
			if (!visited[y - 1][x]){
				if (!is_island(x, y - 1, R, C, map, visited)){
					c = false;
				}
			}
		}
	} else c = false;
	if (y < R - 1){
		if (map[y + 1][x] == 1){
			if (!visited[y + 1][x]){
				if (!is_island(x, y + 1, R, C, map, visited)){
					d = false;
				}
			}
		}
	} else d = false;
	
	
	
	
	return (a && b && c && d);
}



int main() {
	
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);
    
	int R, C;
	
	cin >> R >> C;
	
	vector<vector<int> > map(R, vector<int>(C));
	vector<vector<bool> > visited(R, vector<bool>(C, false));
	
    for(int i = 0; i < R; i++)
        for (int j = 0; j < C; j++)
            cin >> map[i][j];
    
    int answer = 0;
    
    for (int i = 1; i < R - 1; i++){
    	for (int j = 1; j < C - 1; j++){
    		if (!visited[i][j] && map[i][j] == 1){
    			if (is_island(j, i, R, C, map, visited)){
    				answer++;
				}
			}
		}
	}
    
    cout << answer << "\n";
    
    return 0;
}
