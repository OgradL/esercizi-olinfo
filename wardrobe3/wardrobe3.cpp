#include <iostream>
#include <vector>
using namespace std;

int main(){

	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int N, K;
	cin >> N >> K;

	string S;
	cin >> S;

	vector<int> cnt(10, 0);
	for (char c : S){
		cnt[c - '0']++;
	}

	vector<long long> pw10(N, 1);
	for (int i = 1; i < N; i++){
		pw10[i] = 10 * pw10[i-1] % K;
	}

	vector<string> sols(K, "");

	auto rec = [&](auto&& rec, int i, int last, long long m, string& curr) -> bool {
		if (i == N){
			if (sols[m] == ""){
				sols[m] = curr;
				return false;
			} else {
				cout << sols[m] << "\n";
				cout << curr << "\n";
				return true;
			}
		}

		int ok = 0;
		for (int x = 0; !ok && x < 10; x++){
			if (x == last) continue;
			int c = cnt[x];
			for (int j = 1; j <= c && !ok; j++){
				m = (m + x * pw10[N-i-j]) % K;
				cnt[x]--;
				curr.push_back('0' + x);
				ok |= rec(rec, i+j, x, m, curr);
			}

			for (int j = 1; j <= c && !ok; j++){
				m = (10 * K + m - x * pw10[N-i-j]) % K;
				curr.pop_back();
				cnt[x]++;
			}
		}

		return ok;
	};

	string s;
	if (!rec(rec, 0, 0, 0, s))
		cout << "-1\n";

	return 0;
}
