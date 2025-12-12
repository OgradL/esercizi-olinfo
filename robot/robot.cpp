#include <iostream>
#include <vector>
using namespace std;

int main(){

	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int N, M, K;
	cin >> N >> M >> K;

	string P;
	cin >> P;

	vector<vector<int>> grid(M, vector<int>(N, -1));
	vector<int> history;

	history.push_back(0);
	grid[0][0] = 0;
	int x = 0, y = 0;
	int t = 0;
	for (char c : P){

		if (c == 'U'){
			y--;
		}
		if (c == 'D'){
			y++;
		}
		if (c == 'R'){
			x++;
		}
		if (c == 'L'){
			x--;
		}


		if (grid[x][y] == -1){
			grid[x][y] = t;
			history.push_back(t);
		}

		t++;
	}

	int not_visited = N * M - history.size();
	int left = K - not_visited;

	if (left <= 0){
		cout << t << "\n";
	} else {
		cout << history[history.size() - left] << "\n";
	}

	return 0;
}
