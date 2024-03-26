#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

int main(){

	int N, Q;
	cin >> N >> Q;

	int c;
	vector<int> cars(N);
	unordered_map<int, int> m, over;
	for (int i = 0; i < N; i++){
		cin >> c;
		m[c] = i;
		cars[i] = c;
	}

	int idx = 0, G, c1, c2;
	for (int i = 0; i < Q; i++){
		cin >> c1;
		c2 = cars[m[c1]-1];

		swap(m[c1], m[c2]);
		swap(cars[m[c1]], cars[m[c2]]);

		over[c2]++;
		if (over[idx] < over[c2]) idx = c2;
		else if (over[idx] == over[c2] && c2 < idx) idx = c2;

		cout << idx << "\n";
	}


	return 0;
}