#include <map>
#include <string>
using namespace std;

int fotosintesi (int N, std::string S) {
	map<int, map<int, int>> m;

	int ans = 0;
	int a = 0, b = 0, c = 0;
	for (int i = 0; i < N; i++){
		a += S[i] == 'A';
		b += S[i] == 'B';
		c += S[i] == 'C';

		if (m[a - b].count(a - c)){
			ans = max(ans, i - m[a - b][a - c]);
		} else {
			m[a - b][a - c] = i;
		}
	}

	return ans;
}
