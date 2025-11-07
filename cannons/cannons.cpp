#include <iostream>
#include <vector>
#include <deque>
using namespace std;

int main(){

	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int N;
	cin >> N;

	vector<int> T(N);
	for (int& x : T)
		cin >> x;

	vector<int> dist(N, 1e9);
	dist[0] = 0;

	deque<int> q;
	q.push_front(0);

	while (!q.empty()){
		int n = q.front();
		q.pop_front();

		if (dist[T[n]] > dist[n]){
			q.push_front(T[n]);
			dist[T[n]] = dist[n];
		}

		if (n > 0 && dist[n-1] > dist[n] + 1){
			q.push_back(n-1);
			dist[n-1] = dist[n] + 1;
		}
		
		if (n < N-1 && dist[n+1] > dist[n] + 1){
			q.push_back(n+1);
			dist[n+1] = dist[n] + 1;
		}
	}

	cout << dist[N-1] << "\n";

	return 0;
}
