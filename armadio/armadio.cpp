#include <iostream>
#include <vector>
using namespace std;

int nd(int x){
	int ans = 1;
	for (int i = 2; i < x / 2; i++){
		ans += !(x%i);
	}
	return ans;
}

void evadi(int Q, vector<int>& N){

	for (int i = 0; i < Q; i++){
		int ans = 0;
		for (int g = 1; g <= N[i]; g++){
			if (N[i] % g == 0){
				int d = N[i]/g - 2 * nd(N[i]/g - 1) - (((N[i]/g - 1) % 2 == 0) && ((N[i]/g - 1) > 2));
				cout << N[i] << " " << g << " " << d << "\n";
				ans += d;
			}
		}
		N[i] = ans;
	}
}
