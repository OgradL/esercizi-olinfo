#include <iostream>
#include <vector>
using namespace std;

struct op{
	int x0, y0, x1, y1;
	long long v;
};

int main(){

	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int N, M;
	cin >> N >> M;

	vector<vector<long long>> A(N, vector<long long>(M));

	for (int i = 0; i < N; i++){
		for (int j = 0; j < M; j++){
			cin >> A[i][j];
		}
	}

	vector<op> operations;

	auto apply = [&](int x0, int y0, int x1, int y1, long long v){
		if (v == 0)
			return;

		if (x0 > x1)
			swap(x0, x1);
		
		if (y0 > y1)
			swap(y0, y1);

		operations.push_back({x0, y0, x1, y1, v});

		A[x0][y0] += v;
		A[(x0+x1)/2][(y0+y1)/2] += v;
		A[x1][y1] += v;
	};

	auto fix = [&](int x, int y, int dx, int dy){

		long long d = 1e18;
		for (int i = 1; i <= 3; i++){
			d = min(d, A[x - dx*i][y - dy*i]);
		}

		d -= A[x][y];

		if (d < 0){
			apply(x-dx, y-dy, x-3*dx, y-3*dy, -d);
		}

		apply(x, y, x-2*dx, y-2*dy, -A[x][y]);
	};

	for (int i = N-1; i >= 3; i--){
		for (int j = M-1; j >= 0; j--){
			fix(i, j, 1, 0);
		}
	}

	for (int i = 2; i >= 0; i--){
		for (int j = M-1; j >= 3; j--){
			fix(i, j, 0, 1);
		}
	}


	int ok = 1;
	for (int i = 0; i < 2; i++){
		long long d = A[i+1][0] - A[i][0];
		for (int j = 1; j < 3; j++){
			ok &= d == (A[i+1][j] - A[i][j]);
		}
	}

	if (ok){

		apply(0, 1, 2, 1, A[0][2] - A[0][1]);
		apply(0, 0, 2, 0, A[0][1] - A[0][0]);

		for (int i = 0; i < 3; i++)
			apply(i, 0, i, 2, -A[i][0]);
	}


	if (!ok){
		cout << "NO\n";
		return 0;
	}

	cout << "YES\n";
	cout << operations.size() << "\n";
	for (auto [x0, y0, x1, y1, v] : operations){
		cout << x0+1 << " " << y0+1 << " " << x1+1 << " " << y1+1 << " " << v << "\n";
	}

	return 0;
}
