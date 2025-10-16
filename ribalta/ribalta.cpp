#include <string>
#include <vector>
using namespace std;

int ribalta(int N, string S) {
	vector<int> suffix(N+1, 0);
	for (int i = N-1; i >= 0; i--){
		suffix[i] = suffix[i+1] + (S[i] == '1');
	}

	int best = suffix[0];
	int prefix = 0;
	for (int i = 0; i < N; i++){
		prefix += S[i] == '0';
		best = max(best, prefix + suffix[i+1]);
	}

	return best;
}
