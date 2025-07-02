#include <algorithm>
#include <vector>

using namespace std;

vector<int> count(int N, vector<int> S, vector<int> P) {

	vector<int> order(N);
	for (int i = 0; i < N; i++){
		order[i] = i;
	}

	sort(order.begin(), order.end(), [&](int a, int b){
		return P[a] < P[b];
	});

	S.push_back(0);
	vector<int> dominated(N, 0), dcnt(N, 0);

	int b0 = N, b1 = N;

	int chain = 0;

	for (int x : order){
		if (S[x] > S[b0]){
			dominated[x] = 0;
			chain++;
			b1 = b0;
			b0 = x;
		} else if (S[x] > S[b1]){
			dominated[x] = 1;
			dcnt[b0]++;
			b1 = x;
		} else {
			dominated[x] = 1;
		}
	}

	vector<int> ans(N);

	for (int i = 0; i < N; i++){
		if (dominated[i]){
			ans[i] = chain;
		} else {
			ans[i] = chain + dcnt[i] - 1;
		}
	}

	return ans;
}
