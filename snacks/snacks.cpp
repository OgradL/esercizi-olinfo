#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(){

	int N,X;
	cin >> N >> X;

	vector<int> V(N);
	for (int &n : V) cin >> n;
	sort(V.begin(), V.end());

	int ans = 0;
	for (int i = 0; i < N; i++){
		if (i < N-1){
			if (V[i] + V[i+1] <= X){
				i++;
			}
		}
		ans++;
	}
	
	cout << ans << "\n";

	return 0;
}