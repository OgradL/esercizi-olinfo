#include <iostream>
#include <vector>
using namespace std;

int main(){

	int N, K;
	cin >> N >> K;

	vector<int> C(N);
	for (int &i : C) cin >> i;

	long long ans = 0;

	vector<int> trash(N, 0);
	int bin, bags;
	while (K--){
		cin >> bin >> bags;
		
		if (trash[bin] + bags > C[bin]){
			ans += (C[bin] - trash[bin]);
			trash[bin] = 0;
		}
		trash[bin] += bags;
	}

	for (int i = 0; i < N; i++){
		if (trash[i] != 0) ans += C[i] - trash[i];
	}

	cout << ans << "\n";

	return 0;
}