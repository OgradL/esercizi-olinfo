#include <iostream>
#include <vector>
using namespace std;


vector<int> cucina(int N, int K, int X, vector<int> H){
	vector<int> ppt(X, 0);
	for (int n : H)
		ppt[n]++;

	vector<int> ans(X);
	int cap = 1, fed, pp = 0;
	for (int i = X-1; i >= 0; i--){
		fed = min(cap, ppt[i]);
		pp += fed;
		cap = min(cap + 1 - fed, K);
		ans[i] = pp;
	}
	return ans;
}