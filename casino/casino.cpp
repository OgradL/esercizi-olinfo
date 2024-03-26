#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

int compare(string& a, int offa, int offb, int M){

	for (int i = 0; i < M; i++){
		if (a[(i+offa)%M] > a[(i+offb)%M]){
			return 0;
		} else if (a[(i+offa)%M] < a[(i+offb)%M]){
			return 1;
		}
	}

	return 0;
}

void min_rot(string& s){
	int n = s.size();

	int res = 0;
	for (int l = 0; l < n;){
		res = l;
		int r = l, p = l + 1;
		for (; r < n; ++r, ++p){
			char c = (p < n) ? s[p] : s[p - n];
			if (s[r] > c) break;
			if (s[r] < c) r = l - 1;
		}
		l = max(r, l + p - r);
	}

	s = s.substr(res, n - res) + s.substr(0, res);
}

int main(){

	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int N, M;
	cin >> N >> M;

	string str;
	long long ans = 0;
	unordered_map<string, int> m;
	for (int i = 0; i < N; i++){
		cin >> str;
		min_rot(str);
		ans += m[str]++;
	}

	cout << ans << "\n";

	return 0;
}