#include <iostream>
#include <vector>
using namespace std;

#define pb push_back

char solve(int N, int i, vector<int>& p){

	if (i == 1){
		if (N == 1)
			return 'P';
		return 'S';
	}

	if (N <= p[i-1])
		return solve(N, i-1, p);

	if (N == p[i-1]+1)
		return 'P';

	if (N > p[i-1] && N < p[i-1] + 3 + i){
		return 'S';
	}

	return solve(N - p[i-1] - 2 - i, i-1, p);
}


int main() {

	int N;
	cin >> N;

	int v = 3;
	
	vector<int> p = {0, v};
	int i = 1;
	while (v < N){
		p.pb(v = 2*v + 3 + (i++));
	}

	cout << solve(N, i, p) << "\n";
	

	return 0;
}