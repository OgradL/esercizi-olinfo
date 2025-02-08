#include <iostream>
#include <vector>
using namespace std;

int main(){

	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int N;
	cin >> N;

	vector<int> V(N);
	for (int& x : V)
		cin >> x;

	int best = 0;
	for (int i = 0; i < 2*N-1; i++){
		int l = i/2, r = (i+1)/2;
		int assigned = 0;
		while (l >= 0 && r < N){
			if (V[l] != V[r]){
				if (min(V[l], V[r]) != -1)
					break;
				if (assigned && max(V[l], V[r]) != assigned)
					break;
				assigned = max(V[l], V[r]);
			}

			best = max(best, r - l + 1);
			
			--l;
			++r;
		}
	}

	cout << best << "\n";

	return 0;
}
