#include <iostream>
#include <vector>
#include <tuple>
using namespace std;

using ll = long long;

tuple<char, ll, ll> prisonier(ll W, vector<ll> notebook);

int main(){

	int N;
	cin >> N;

	vector<vector<long long>> notebook(N);

	long long C = 1, M = 0, W = 0;
	while (true){

		for (int i = 0; i < N; i++){
			auto [op, x, y] = prisonier(W, notebook[i]);
			if (op == 'a'){
				if (x == N)
					cout << "Correct: " << N << "\n";
				else
					cout << "Wrong: " << x << " " << N << "\n";
				cout << M * M * C << "\n";
				return 0;
			} else {
				W = x;
				M = max(M, W);
				notebook[i].push_back(y);
			}
		}

		C++;
	}



	return 0;
}
