#include <iostream>
#include <vector>
using namespace std;

int main(){

	cin.tie(0);
	cin.sync_with_stdio(false);

	int N, M;
	cin >> N >> M;


	vector<int> pos(N), all(N);
	for (int i = 0; i < N; i++){
		all[i] = i;
		pos[i] = i;
	}

	int A, B;
	for (int i = 0; i < M; i++){
		cin >> A >> B;
		int where1 = pos[A];
		int where2 = pos[B];
		swap(pos[A], pos[B]);
		swap(all[where1], all[where2]);
	}


	cout << all[0] << "\n";

	return 0;
}