#include <stdio.h>
#include <fstream>
#include <iostream>
#include <vector>
using namespace std;

#define ll long long

ll sumxor(ll A){
	int v = A % 4;
	if (v == 0)
		return A;
	if (v == 1)
		return 1;
	if (v == 2)
		return A ^ 1;
	if (v == 3)
		return 0;
}

ll maxxor(ll A){
	ll N = sumxor(A);
	ll ris = 0;
	for (int b = 34; b >= 0; b--){
		if ((N ^ (1LL << b)) >= N){
			if ((ris + (1LL << b)) <= A){
				ris += (1LL << b);
			}
		}
	}

	return ris ^ N;
}


int main() {

	cin.tie(0);
	cin.sync_with_stdio(false);
	int Q, A;
	cin >> Q;

	for (int i = 0; i < Q; i++) {
		cin >> A;

		cout << sumxor(A) << " " << maxxor(A) << "\n";
	}


	return 0;
}
