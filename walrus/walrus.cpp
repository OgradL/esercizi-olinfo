#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(){

	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int T;
	cin >> T;
	
	while (T--){
		int N;
		cin >> N;

		string s;
		cin >> s;

		vector<int> groups;
		char last = '-';
		for (char c : s){
			if (c == '.'){
				if (c != last){
					groups.push_back(0);
				}
				groups.back()++;
			}
			last = c;
		}

		sort(groups.begin(), groups.end(), greater<int>());

		int ans = 0, i = 0;
		for (int x : groups){
			ans = max(ans, x / 2 + ++i);
		}

		cout << groups.size() << " " << ans << "\n";
	}

	return 0;
}
