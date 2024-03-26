#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct query{
	int l, r, i;
};

const long long maxn = 100042;
vector<long long> fen;
int N, Q;

void add(int idx, long long v){
	for (++idx; idx <= N; idx += idx & -idx)
		fen[idx] += v;
}

long long sum(int idx){
	long long ret = 0;
	for (++idx; idx > 0; idx -= idx & -idx)
		ret += fen[idx];
	return ret;
}

void solve(){

	cin >> N;
	
	vector<long long> V(N);
	for (auto& x : V)
		cin >> x;
	
	cin >> Q;

	vector<query> queries(Q);
	int idx = 0;
	for (auto& [l, r, i] : queries){
		cin >> l >> r;
		--l; --r;
		i = idx++;
	}

	sort(queries.begin(), queries.end(), [](query& a, query& b){
		return a.r < b.r;
	});

	vector<long long> answer(Q);
	vector<long long> divisors(1, 1), new_divisors;
	fen.assign(N+1, 0);
	add(0, 1);
	int rb = 0;
	for (auto& [l, r, i] : queries){
		while (rb < r){
			new_divisors.clear();
			rb++;
			for (long long d : divisors){
				if (V[rb] % (d + 1) == 0)
					new_divisors.push_back(d + 1);
			}
			new_divisors.push_back(1);
			divisors = new_divisors;
			for (long long d : divisors){
				add(rb - d + 1, 1);
			}
		}
		
		answer[i] = sum(r) - sum(l-1);
	}

	for (auto& x : answer)
		cout << x << '\n';
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int T;
	cin >> T;
	while (T--) solve();
	return 0;
}