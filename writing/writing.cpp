#include <iostream>
using namespace std;

int main(){

	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	int g, N;
	cin >> g >> N;


	int W['z'+1], S['z'+1];
	for (int i = 0; i <= 'z'; i++) W[i] = S[i] = 0;


	int diff = 0;
	char c;
	for (int i = 0; i < g; i++){
		cin >> c;
		diff += !W[c];
		W[c]++;
	}

	char s[5001];
	int last_c = 0;
	for (int i = 0; i < g; i++){
		cin >> s[last_c];
		last_c = (last_c + 1) % 5001;
		diff += (W[s[i]] == S[s[i]]);
		S[s[i]]++;
		diff -= (W[s[i]] == S[s[i]]);
	}
	int ans = 0;
	if (diff == 0) ans++;

	N = N - g;
	for (int i = 0; N--; i=(i+1)%5001){
		cin >> s[last_c];
		diff += (W[s[i]] == S[s[i]]);
		S[s[i]]--;
		diff -= (W[s[i]] == S[s[i]]);
		
		diff += (W[s[last_c]] == S[s[last_c]]);
		S[s[last_c]]++;
		diff -= (W[s[last_c]] == S[s[last_c]]);

		if (diff == 0) ans++;
		last_c = (last_c + 1) % 5001;
	}
	
	cout << ans << "\n";

	return 0;
}