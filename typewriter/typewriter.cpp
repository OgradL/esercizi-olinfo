#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
	string S1, S2, S3;
	cin >> S1 >> S2 >> S3;
	
	int N1 = S1.size();
	int N2 = S2.size();
	int N3 = S3.size();

	int ok = 1;
	int i1, i2, i3, c1, c2, c3, m, s;
	i1 = i2 = i3 = 0;
	string ans;
	for (;;){
		c1 = c2 = c3 = 1;
		s = (i1 == N1) + (i2 == N2) + (i3 == N3);
		if (s){
			ok = s == 3;
			break;
		}
		if (S1[i1] != S2[i2] || S2[i2] != S3[i3]){
			ok = 0;
			break;
		}
		++i1, ++i2, ++i3;
		while (i1 < N1 && S1[i1] == S1[i1-1])
			++i1, ++c1;
		while (i2 < N2 && S2[i2] == S2[i2-1])
			++i2, ++c2;
		while (i3 < N3 && S3[i3] == S3[i3-1])
			++i3, ++c3;
		m = c1 + c2 + c3 - min({c1, c2, c3}) - max({c1, c2, c3});
		for (;m--;){
			ans += S1[i1-1];
		}
	}
	
	if (ok){
		cout << ans << "\n";
	} else {
		cout << "IMPOSSIBLE\n";
	}
	
	return 0;
}
