#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool ordina(int N, vector<int> V, vector<int> &L) {

	vector<int> ans;
	ans.reserve(N);
	int last = -1;
	for (int i = 0; i < N - 1; i++){
		if (V[i] < V[i+1]){
			reverse(V.begin() + last + 1, V.begin() + i + 1);
			L.push_back(i - last);
			last = i;
		}
	}
	L.push_back(N - last - 1);
	reverse(V.begin() + last + 1, V.begin() + N);

	for (int i = 0; i < N-1; i++){
		if (V[i] > V[i+1])
			return false;
	}
	
	return true;
}
