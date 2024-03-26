#include <iostream>
#include <vector>
using namespace std;

#define MOD (long long) (1e9+7)

int main(){
	
	int N;
	cin >> N;
	
	vector<int> V(N);
	for (int &n : V)
		cin >> n;
	
	vector<int> pref (N, 0);
	pref[0] = 1;
	
	for (int i = 1; i < N; i++){
		pref[i] = (pref[i-1] + ((V[i] < i) ? pref[i-V[i]-1] : 0) + 1) % MOD;
	}
	
	cout << pref[N-1]+1 << "\n";
	
	return 0;
}