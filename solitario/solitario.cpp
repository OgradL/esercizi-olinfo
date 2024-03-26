#include <bits/stdc++.h>

using namespace std;

bool is_valid(int x, int y, vector<vector<int> >& board){
	
	
	
	
}


int f(int x, int y, int N, int M, vector<vector<int> >& board){
	
	x++;
	if (x >= N){
		x = 0;
		y++;
		if (y >= M){
			return 0;
		}
	}
	
	if (is_valid(x, y))
	
}

int main() {
    
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    
    int N, M;
    
    cin >> N >> M;
    
    int ans = 0;
    
    vector<vector<int> > board(N, vector<int>(M));
    
    f(0, 0, N, M, board);
    
    cout << ans << "\n";
    
}
