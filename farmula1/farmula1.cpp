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

	vector<int> scores = {0, 25, 18, 15, 12, 10, 8, 6, 4, 2, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
	
	for (int t = 0; t < T; t++){
		int N;
		cin >> N;

		int p1 = 0, p2 = 0;
		for (int i = 0; i < N; i++){
			int x;
			cin >> x;
			
			p1 += scores[x];
			p2 += scores[1+(x==1)];
		}
		if (p1 >= p2){
			cout << "Champion\n";
		} else {
			cout << "Practice harder\n";
		}
	}

	return 0;
}