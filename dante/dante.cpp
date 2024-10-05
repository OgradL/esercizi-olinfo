#include <vector>

using namespace std;

int rimembra(int N, int K, vector<int> V){
	
	int ans = 0, i = 0, j = 0, c = K;
	while (j < N){
		if (c > 0 || V[j] == 1){
			c -= V[j++] == 0;
		} else {
			c += V[i++] == 0;
		}
		ans = max(ans, j - i);
	}

	return ans;
}
