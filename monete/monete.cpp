#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;

int monete(int N, int v[]){

	unordered_map<int, int> m;

	int ans = 0, ma;
	vector<int> s(N, 0);
	for (int i = 2; i < N; i++){
		ma = 0;
		if (s[i-1]) continue;
		m.clear();
		for (int j = i-1; j < N; j += i){
			ma = max(ma, ++m[v[j]]);
			s[j] = 1;
		}
		s[i-1] = 1;
		ans = max(ans, ma);
	}

	return ans;
}