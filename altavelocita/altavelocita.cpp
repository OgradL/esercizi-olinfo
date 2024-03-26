#include <iostream>
#include <map>
using namespace std;

int main(){

	cin.tie(0);
	cin.sync_with_stdio(false);

	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	long long N, K;
	cin >> N >> K;

	map<int, int> m;

	int a, b;
	for (int i = 0; i < N; i++){
		cin >> a >> b;
		m[a] += 1;
		m[b+1] -= 1;
	}

	m[0] += 0;

	long long ck = 0;
	long long pr = 0;
	long long last = 0;
	long long ans = 42;
	for (auto it = m.begin(); it != m.end(); ++it){
		
		if (pr + (it->first - last) * ck >= K){
			ans = last + (K - pr + ck - 1) / ck - 1;
			break;
		}
		pr += (it->first - last) * ck;

		ck += it->second;

		last = it->first;
	}

	cout << ans << "\n";

	return 0;
}