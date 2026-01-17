#include <iostream>
#include <vector>
using namespace std;

int main(){

	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int N, T, K;
	cin >> N >> T >> K;

	vector<int> A(T);
	for (int& x : A)
		cin >> x;

	int ans = -1;
	int cnt = 0;
	for (int i = 0; i < T; i++){
		if (A[i] * 100 >= 67 * N){
			cnt++;
		} else {
			cnt = 0;
		}
		if (cnt == K){
			ans = i - K + 2;
			break;
		}
	}

	cout << ans << "\n";

	return 0;
}
