#include <iostream>
#include <set>
#include <map>
using namespace std;

long long N, M, Q;
multiset<long long> dims;
map<long long, long long> cows;

pair<long long, long long> next_step(long long n, long long m){
	return {n % m, m % n};
}

long long get_idx(long long r, long long c){
	long long idx = 0;
	long long n = N, m = M;

	while (true){
		auto [nn, nm] = next_step(n, m);

		if (nn <= r || nm <= c)
			break;

		idx += (n - nn) / m + (m - nm) / n;

		n = nn, m = nm;
	}

	if (n > m){
		idx += (n - r - 1) / m;
	}
	if (m > n){
		idx += (m - c - 1) / n;
	}

	return idx;
}

void add(long long r, long long c){
	long long idx = get_idx(N-r-1, M-c-1);

	if (cows[idx] != 0)
		dims.erase(dims.find(cows[idx]));
	++cows[idx];
	dims.insert(cows[idx]);
}

void remove(long long r, long long c){
	long long idx = get_idx(N-r-1, M-c-1);

	dims.erase(dims.find(cows[idx]));
	--cows[idx];
	if (cows[idx] != 0)
		dims.insert(cows[idx]);
}

long long count(){
	if (dims.size())
		return *dims.rbegin();
	return 0;
}

int main(){

	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> N >> M >> Q;

	char op;
	long long r, c;
	while (Q--){
		cin >> op;

		if (op == 'a'){
			cin >> r >> c;
			add(r, c);
		}
		if (op == 't'){
			cin >> r >> c;
			remove(r, c);
		}
		if (op == 'c'){
			cout << count() << "\n";
		}
	}

	return 0;
}
