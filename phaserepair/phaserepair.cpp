#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(){

	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int N, M;
	cin >> N >> M;

	vector<int> V(N);
	for (int& x : V){
		cin >> x;
	}

	sort(V.begin(), V.end());
	V.erase(unique(V.begin(), V.end()), V.end());

	int start = 0, diff = M;
	int last = V.back();
	for (int i = 0; i < V.size(); i++){
		int d = (last - V[i] + M) % M;
		if (d < diff){
			diff = d;
			start = i;
		}
		last = V[i];
	}

	cout << diff << "\n";
	for (int x = V[start], cnt = 0; cnt < diff; x++, cnt++){
		cout << x%M << " ";
	}
	cout << "\n";

	return 0;
}
