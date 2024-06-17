#include <iostream>
#include <vector>
#include <math.h>
#include <algorithm>
using namespace std;

struct FenwickTree{

	int n;
	vector<int> bit;
	vector<int> vals;

	FenwickTree(int N){
		n = N + 1;
		bit.assign(n, 0);
		vals.assign(n, 0);
	}

	void set_max(int i, int val){
		i++;
		vals[i] = max(vals[i], val);
		for (int idx = i; idx < n; idx += idx & -idx){
			if (vals[bit[idx]] < val)
				bit[idx] = i;
		}
	}
	
	int get_max(int idx){
		int ret = 0;
		for (idx++; idx > 0; idx -= idx & -idx){
			if (vals[bit[idx]] > vals[ret])
				ret = bit[idx];
		}
		return ret;
	}
};

int main(){

	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int N, M, K;
	cin >> N >> M >> K;

	vector<long long> A(N), B(M);
	for (long long& x : A)
		cin >> x;
	for (long long& x : B)
		cin >> x;

	vector<long long> prefB(M);
	prefB[0] = B[0];
	for (int i = 1; i < M; i++){
		prefB[i] = prefB[i-1] + B[i];
	}

	FenwickTree fentree(M);
	vector<int> prev(N, -1), simm(M, -1), simm2(N, -1);
	long long sum = 0;
	for (int i = 0; i < N; i++){
		sum += A[i];
		auto it = lower_bound(prefB.begin(), prefB.end(), sum);
		if (*it == sum){
			int idx = it - prefB.begin();
			int v = fentree.get_max(idx-1);
			int val = fentree.vals[v];
			if (fentree.vals[idx+1] <= val){
				fentree.set_max(idx, val+1);
				if (v != 0)
					prev[i] = simm[v-1];
				simm[idx] = i;
				simm2[i] = idx;
			}
		}
	}

	int idx = prev[N-1];
	if (simm[M-1] != N-1)
		idx = -1;
	vector<int> cuts_a, cuts_b;
	while (idx >= 0 && cuts_a.size() < K-1){
		cuts_a.push_back(idx+1);
		cuts_b.push_back(simm2[idx]+1);
		idx = prev[idx];
	}

	reverse(cuts_a.begin(), cuts_a.end());
	reverse(cuts_b.begin(), cuts_b.end());
	if (cuts_a.size() >= K-1){
		for (int x : cuts_a)
			cout << x << " ";
		cout << "\n";
		for (int x : cuts_b)
			cout << x << " ";
		cout << "\n";
	} else {
		cout << "-1\n";
	}
	
	return 0;
}
