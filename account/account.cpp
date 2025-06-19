#include <string>
using namespace std;

void rispondi(string out);
int chiedi(int K);

void indovina(int N){
	
	string ans(N, 'a');

	int i = N * (N+1) / 2;
	for (int c = 'a' + N - 1; c > 'a'; c--){
		int q = chiedi(i);
		ans[N-q] = c;
		i -= q;
	}
	
	rispondi(ans);
}
