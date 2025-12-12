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


	int james = 1;
	for (int i = 1; i < N; i++){
		james &= V[i] == i+1 || V[i] == V[i-1];
	}

	cout << "1 ";

	int last = 1;
	for (int i = 1; i < N; i++){
		if (V[i] != V[i-1]){
			if (james){
				last++;
			} else {
				last = i+1;
			}
		}

		cout << last << " ";
	}

	cout << "\n";

	return 0;
}
