#include <iostream>
#include <vector>
using namespace std;

int main(){

	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int N;
	cin >> N;

	vector<int> P(N);
	for (int& x : P)
		cin >> x;
	
	vector<int> cycles;
	vector<pair<int, int>> numbers(N, {-1, 0});

	int curr = 0, idx;
	for (int i = 0; i < N; i++){
		if (numbers[i].first != -1) continue;
		idx = 0;
		numbers[i] = {curr, idx++};
		int x = P[i];
		while (x != i){
			numbers[x] = {curr, idx++};
			x = P[x];
		}
		curr++;
		cycles.push_back(idx);
	}

	int Q;
	cin >> Q;

	int a, b;
	while (Q--){
		cin >> a >> b;
		if (numbers[a].first != numbers[b].first){
			cout << "-1 ";
		} else {
			cout << min(
				abs(numbers[a].second - numbers[b].second),
				cycles[numbers[a].first] - abs(numbers[a].second - numbers[b].second)
			) << " ";
		}
	}


	return 0;
}