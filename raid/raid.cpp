#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int tall(int i, vector<int>& H){
	int a = i == 0 ? 1 : H[i] > H[i-1];
	int b = i == int(H.size())-1 ? 1 : H[i] > H[i+1];
	return a && b;
}

int main(){

	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int N, P;
	cin >> N >> P;

	vector<int> H(N);
	for (int& x : H)
		cin >> x;
	
	queue<pair<int, int>> q;
	for (int i = 0; i < N; i++){
		if (tall(i, H))
			q.push({i, 0});
	}

	int ans = 0;
	vector<int> v(N, 0);
	while (!q.empty()){
		auto [n, p] = q.front();
		q.pop();
		cout << n << " " << p << " " << tall(n, H) << "\n";
		if (p == P)
			continue;
		if (!tall(n, H))
			continue;
		ans++;
		H[n] = 0;
		if (n > 0 && !v[n-1])
			q.push({n-1, p+1}), v[n-1] = 1;
		if (n < N-1 && !v[n+1])
			q.push({n+1, p+1}), v[n+1] = 1;
	}

	cout << ans << "\n";

	return 0;
}