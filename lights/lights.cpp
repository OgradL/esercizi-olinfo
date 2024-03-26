#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;


int main(){

	int N, C;
	cin >> N >> C;
	vector<int> L(N);
	for (int &i : L) cin >> i;

	int i = 0, j = 0;

	unordered_map<int, int> current_colors;
	int count = 0, ans = 1e8;
	while (i < N || j < N){
		if (count < C && i < N){
			current_colors[L[i]]++;
			if (current_colors[L[i]] == 1) count++;
			i++;
		} else {
			if (count == C)
				ans = min(ans, i - j);
			current_colors[L[j]]--;
			if (current_colors[L[j]] == 0) count--;
			j++;
		}
		// cout << i << " " << j << " " << i - j << " - " << count << "\n";
	}

	cout << ans << "\n";

	return 0;
}