#include <vector>
#include <math.h>
using namespace std;

int alzati(int N, int M, int X[], int Y[]){

	vector<int> dist(M, 2e9), visited(M, 0);

	auto d1 = [&](int i, int j){
		int d = abs(X[i] - X[j]) + abs(Y[i] - Y[j]);
		d -= X[i] != X[j] && Y[i] != Y[j];
		return d / 2;
	};

	int next = 0;
	for (int i = 0; i < M; i++){
		dist[i] = min(X[i], N - Y[i] - 1);
		if (dist[i] < dist[next])
			next = i;
	}

	int ans = 2e9;
	int curr;
	while (next != -1){
		curr = next;
		next = -1;
		visited[curr] = 1;

		ans = min(ans, max(dist[curr], min(Y[curr], N - X[curr] - 1)));

		for (int i = 0; i < M; i++){
			if (!visited[i]){
				dist[i] = min(dist[i], max(dist[curr], d1(curr, i)));
				
				if (next == -1 || dist[i] < dist[next]){
					next = i;
				}
			}
		}
	}

	return ans - 1;
}
