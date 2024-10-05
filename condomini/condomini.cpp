#include <vector>
#include <algorithm>
using namespace std;

struct minstack{
	vector<pair<int, int>> vals;
	pair<int, int> push(int x){
		int m = 1, v, used = 1;
		while (vals.size() && vals.back().first <= x){
			v = vals.back().second + (vals.back().first != x);
			if (v > m || (v == m && used)){
				m = max(m, v);
				used = vals.back().first != x;
			}
			vals.pop_back();
		}
		
		vals.push_back({x, m});
		return {m, used};
	}
};

vector<int> solve(int N, vector<int>& H, vector<int>& used){
	vector<int> ans(N);

	minstack mst;
	for (int i = 0; i < N; i++){
		auto t = mst.push(H[i]);
		ans[i] = t.first;
		used[i] = t.second;
	}

	return ans;
}

int sbugiarda(int N, vector<int> H) {

	vector<int> usedl(N), usedr(N);

	vector<int> ansl = solve(N, H, usedl);
	reverse(H.begin(), H.end());

	vector<int> ansr = solve(N, H, usedr);
	reverse(ansr.begin(), ansr.end());
	reverse(usedr.begin(), usedr.end());

	int ans = 0;
	for (int i = 0; i < N; i++){
		ans = max(ans, ansl[i] + ansr[i] - (usedl[i] & usedr[i]));
	}

	return ans;
}
