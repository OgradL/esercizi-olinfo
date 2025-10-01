#include <vector>
#include <string>
#include <iostream>
using namespace std;

int N;
vector<vector<int>> diag1, diag2;
vector<string> M1, M2;

void init(int N, vector<string> M) {
	::N = N;
	::M1 = M;
	::M2 = M;

	for (int i = 0; i < N; i++){
		for (int j = 0; j < N/2; j++){
			swap(M2[i][j], M2[i][N-1-j]);
		}
	}

	diag1.assign(2*N, vector<int>(N+1, 0));
	diag2.assign(2*N, vector<int>(N+1, 0));

	for (int i = 0; i < 2*N; i++){
		for (int x = 0; x < N; x++){
			int y = i - x;
			if (y < 0)
				break;
			if (y >= N)
				continue;

			diag1[i][x+1] = M1[x][y] - '0';
			diag1[i][x+1] += diag1[i][x];
		}
	}

	for (int i = 0; i < 2*N; i++){
		for (int x = 0; x < N; x++){
			int y = i - x;
			if (y < 0)
				break;
			if (y >= N)
				continue;

			diag2[i][x+1] = M2[x][y] - '0';
			diag2[i][x+1] += diag2[i][x];
		}
	}
}

bool query(int h, int x, int y) {
	
	if (h == 1){
		return M1[x][y] == M1[x+1][y+1] && M1[x][y] != M1[x+1][y] && M1[x][y] != M1[x][y+1];
	}

	auto get_pref = [&](vector<int>& pref, int l, int r) -> int {
		return pref[r+1] - pref[l];
	};

	auto get_diag = [&](vector<vector<int>>& diag, int x, int y) -> bool {
		int ok1 = 1, ok2 = 1;

		for (int k = 0; k <= 2; k++){
			int d0 = get_pref(diag[x+y+k], x+k, x+h);
			int d1 = get_pref(diag[x+y-k], x, x+h-k);

			ok1 &= d0 == d1;
			ok2 &= d0 == d1;
			if (k == 0){
				ok1 &= d0 == h-k+1;
				ok2 &= d0 == 0;
			} else {
				ok1 &= d0 == 0;
				ok2 &= d0 == h-k+1;
			}
		}

		return ok1 || ok2;
	};

	return get_diag(diag1, x, y+h) || get_diag(diag2, x, N-1-y);
}

// GRADER DI ESEMPIO, NON MODIFICARE

#ifndef EVAL

int main() {
    int N, Q;
    cin >> N >> Q;
    
    vector<string> M(N);
    for (int i = 0; i < N; i++)
        cin >> M[i];
    
    init(N, M);

    for (int i = 0; i < Q; i++) {
        int h, x, y;
        cin >> h >> x >> y;
        cout << query(h, x, y) << '\n';
    }
}

#endif
