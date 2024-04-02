#include <iostream>
#include <vector>
using namespace std;

long long range(int i, int j, vector<long long>& pref){
	return pref[j] - pref[i];
}

long long calc(int i, int j, vector<long long>& pref, vector<long long>& X){
	long long ans = 0;
	int mid = (i+j)/2;
	ans += X[mid] * (mid - i) - range(i, mid, pref);
	ans += range(mid, j, pref) - X[mid] * (j - mid);
	return ans;
}

int main(){
	
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	long long N, B;
	cin >> N >> B;

	vector<long long> X(N);
	vector<long long> pref(N+1, 0);
	for (int i = 0; i < N; i++){
		cin >> X[i];
		pref[i+1] = pref[i] + X[i];
	}

	int i = 0, j = 0, count = 0;
	long long costo = 0;
	int ans = 0;
	while (i < N && j <= N){
		costo = calc(i, j, pref, X);
		if (j == N){
			i++;
		} else if (costo > B){
			i++;
		} else {
			j++;
		}
		costo = calc(i, j, pref, X);
		if (costo <= B)
			ans = max(ans, j - i);
	}

	cout << ans << "\n";

	return 0;
}
