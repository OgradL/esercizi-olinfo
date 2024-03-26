#include <iostream>
#include <vector>
#include <queue>
using namespace std;

#define INF 1e9 + 10

#define F first
#define S second

int ContaPercorsi(int N, int M, int K, int* X, int* Y){

	vector<vector<int>> m(N, vector<int>(M, INF));

	queue<pair<pair<int, int>, int>> q;
	for (int i = 0; i < K; i++)
		q.push({{X[i], Y[i]}, 0});
	
	int px, py, d;
	pair<pair<int, int>, int> n;
	while (!q.empty()){
		n = q.front();
		q.pop();
		px = n.F.F;
		py = n.F.S;
		d = n.S;

		if (px < 0 || px >= N)
			continue;
		if (py < 0 || py >= M)
			continue;
		
		if (m[px][py] < d)
			continue;
		
		m[px][py] = d;

		q.push({{px+1, py}, d+1});
		q.push({{px-1, py}, d+1});
		q.push({{px, py+1}, d+1});
		q.push({{px, py-1}, d+1});
	}


	vector<vector<int>> dp(N, vector<int>(M));
	// visit(0, 0, )

}