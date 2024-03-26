#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

int main(){

	int N;
	cin >> N;

	vector<int> V(N);
	for (int &n : V){
		cin >> n;
	}

	int ans = 0, c;
	for (int i = 0; i < N; i++){
		c = 0;
		for (int j = i+1; j < N; j++){
			c += (V[i] % V[j] == 0) | (V[j] % V[i] == 0);
		}
		ans = max(ans, c);
	}

	cout << ans << "\n";

	return 0;
}