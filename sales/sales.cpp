#include <iostream>
#include <vector>
using namespace std;

int main(){

	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int N;
	cin >> N;

	vector<long long> W(N);
	for (long long& x : W)
		cin >> x;

	int M;
	cin >> M;

	vector<long long> K(M), T(M);
	for (long long& x : K)
		cin >> x;
	for (long long& x : T)
		cin >> x;

	vector<long long> max_weight(N+1, 0);
	for (int i = 0; i < M; i++){
		max_weight[K[i]] = max(max_weight[K[i]], T[i]);
	}
	for (int i = N; i > 0; i--){
		max_weight[i-1] = max(max_weight[i-1], max_weight[i]);
	}

	int ans = 0;
	for (int i = 0; i < N; ){
		int k = 0;
		long long sum = 0;
		while (i < N && sum <= max_weight[k]){
			if (sum + W[i] > max_weight[k+1])
				break;
			k++;
			sum += W[i];
			i++;
		}
		ans++;
	}

	cout << ans << "\n";

	return 0;
}
