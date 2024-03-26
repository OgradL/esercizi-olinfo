#include <iostream>
#include <vector>
#include <queue>
using namespace std;

#define MAXN 200


void calculate(int N, vector<vector<int> >& dists, vector<vector<char> >& grid){
	
	char hash = '#';
	
	queue<pair<pair<int, int>, int>> q;

	q.push({{0, 0}, 0});

	pair<pair<int, int>, int> n;
	int x, y, distance;
	while (!q.empty()){
		n = q.front();
		q.pop();
		x = n.first.first;
		y = n.first.second;
		distance = n.second;

		dists[y][x] = distance;
		
		for (int i = y - 1; i >= 0; i--){
			if (dists[i][x] > distance + 1){
				if (grid[i][x] != hash){
					q.push({{x, i}, distance + 1});
					// (x, i, N, dists, grid, distance + 1);
				} else {
					break;
				}
			}
		}
		for (int i = y + 1; i < N; i++){
			if (dists[i][x] > distance + 1){
				if (grid[i][x] != hash){
					q.push({{x, i}, distance + 1});
					// calculate(x, i, N, dists, grid, distance + 1);
				} else {
					break;
				}
			}
		}
		for (int i = x - 1; i >= 0; i--){
			if (dists[y][i] > distance + 1){
				if (grid[y][i] != hash){
					q.push({{i, y}, distance + 1});
					// calculate(i, y, N, dists, grid, distance + 1);
				} else {
					break;
				}
			}
		}
		for (int i = x + 1; i < N; i++){
			if (dists[y][i] > distance + 1){
				if (grid[y][i] != hash){
					q.push({{i, y}, distance + 1});
					// calculate(i, y, N, dists, grid, distance + 1);
				} else {
					break;
				}
			}
		}
	}
}



int main() {
	
//	freopen("input1.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);
	
	int N;
	
    cin >> N;
    
    
    vector<vector<char> > grid(N, vector<char>(N));
    
    string line;
    
    for(int i = 0; i < N; i++){
        cin >> line;
    	for (int j = 0; j < N; j++){
    		grid[i][j] = line[j];
		}
	}
	
	
	vector<vector<int> > dists(N, vector<int>(N, 100000));
	
	
	calculate(N, dists, grid);
	
	
	if (dists[N-1][N-1] == 100000){
		dists[N-1][N-1] = 1;
	}
	
	cout << (dists[N-1][N-1] - 2) << "\n";
	
    return 0;
}
