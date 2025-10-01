#include <vector>
#include <deque>
using namespace std;

int K;
vector<int> C;
vector<long long> pref;
vector<vector<long long>> bln, bld;

void pianifica(int N, int K, vector<int> C){
	::K = K;
	::C = C;

	bln.assign(N+1, vector<long long>(18, 0));
	bld.assign(N+1, vector<long long>(18, 0));
	pref.assign(N+2, 0);

	deque<pair<long long, long long>> stack;

	for (int i = 0; i < N; i++){
		while (!stack.empty() && stack.back().first >= C[i]){
			stack.pop_back();
		}
		stack.push_back({C[i], i});
		if (stack.front().second <= i - K){
			stack.pop_front();
		}

		pref[i+1] = pref[i] + stack.front().first;
	}
	pref[N+1] = pref[N];

	stack.clear();
	stack.push_back({0, N});

	bln[N].assign(18, N);
	bld[N].assign(18, 0);

	for (int i = N-1; i >= 0; i--){
		while (!stack.empty() && stack.back().first >= C[i]){
			stack.pop_back();
		}

		bln[i][0] = stack.back().second;
		bld[i][0] = (bln[i][0] - i) * C[i];

		for (int j = 1; j < 18; j++){
			bln[i][j] = bln[bln[i][j-1]][j-1];
			bld[i][j] = bld[i][j-1] + bld[bln[i][j-1]][j-1];
		}

		stack.push_back({C[i], i});
	}
}

long long viaggia(int l, int r){
	long long ans = 0;

	int R = min(l + K, r);

	for (int i = 17; i >= 0; i--){
		if (bln[l][i] <= R){
			ans += bld[l][i];
			l = bln[l][i];
		}
	}
	ans += (R - l) * 1LL * C[l];

	ans += pref[r] - pref[R];

	return ans;
}
