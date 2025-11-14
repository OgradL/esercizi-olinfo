#include <iostream>
#include <algorithm>
using namespace std;

void solve(){

	int N, M;
	cin >> N >> M;

	int a = N / 3;
	int b = (N + 1) / 3;

	int p0 = 3, p1 = 0;

	if (M >= a){
		M -= a;
		p1++;
	}

	if (M >= b){
		M -= b;
		p1++;
	}

	p0 -= min({p1, M, 2});

	if (p0 > p1){
		cout << "tommaso\n";
	} else if (p0 == p1){
		cout << "draw\n";
	} else {
		cout << "filippo\n";
	}
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
