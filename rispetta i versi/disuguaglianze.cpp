#include <bits/stdc++.h>

using namespace std;

int main(){
	
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	
	int N;
	cin >> N;
	
	string versi;
	cin >> versi;
	
	
	vector<int> A;
	A.resize(N);
	
	int mi = 1;
	int ma = 1;
	A[0] = 1;
	for (int i = 1; i < N; i++){
		if (versi[i - 1] == '>'){
			A[i] = mi - 1;
			mi -= 1;
		} else {
			A[i] = ma + 1;
			ma += 1;
		}
	}
	
	int offset = abs(mi - 1);
	
	
	for (int i = 0; i < N; i++){
		cout << A[i] + offset << " ";
	}
	cout << "\n";
}
