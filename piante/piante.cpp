#include <iostream>
#include <vector>
using namespace std;

int pollice_verde(int N, vector<int> H){
	if (N == 1)
		return 1;

	int ans = 0, t = 0;

	for (int i = 0; i < N; i++){
		t = 0;
		if (i != 0)
			t += H[i] >= H[i-1];
		if (i != N-1)
			t += H[i] >= H[i+1];
		ans += t == ((i != 0) + (i != N-1));
	}

	return ans;
}