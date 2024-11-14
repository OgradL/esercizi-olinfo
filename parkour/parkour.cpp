#include <iostream>
using namespace std;

int main(){

	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int N, M;
	cin >> N >> M;

	if (N > M){
		cout << "-1\n";
		return 0;
	}

	string line(M, '.');
	cout << line << "\n";

	for (int i = 1; i < N; i++){
		line[i-1] = '#';
		cout << line << "\n";
	}

	return 0;
}
