#include <iostream>
#include <vector>
using namespace std;

int main(){

	int N;
	cin >> N;

	vector<int> A(N);

	for (int i = 0; i < N; i++){
		cin >> A[i];
	}

	int v = A.back(), ans = 1;

	for (int i = N - 2; i >= 0; i--){
		if (A[i] >= v){
			ans++;
			v = A[i];
		}
	}

	cout << ans << "\n";

	return 0;
}