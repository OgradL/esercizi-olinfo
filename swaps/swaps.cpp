#include <iostream>
#include <vector>
using namespace std;

int gcd(int a, int b){
	return b == 0 ? a : gcd(b, a % b);
}

int main(){

	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	int N;
	cin >> N;

	vector<int> P(N);
	for (int &n : P)
		cin >> n;
	
	int ans = 0, d = 0;
	for (int i = i; i < N; i++){
		while (P[i] != i+1){
			d = d ? gcd(d, P[P[i]-1] - P[i]) : P[P[i]-1] - P[i];
			swap(P[i], P[P[i]-1]);
			ans++;
		}
	}

	for (int i = 1; i <= N; i++){
		cout << (!(d % i) ? ans : -1) << ' ';
	}
	cout << "\n";

	return 0;
}