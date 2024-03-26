#include <iostream>
#include <vector>
using namespace std;

bool heights(int N, vector<int> Z, vector<int> &H){
	H[0] = Z[0];
	Z.push_back(Z.back());
	for (int i = 1; i < N; i++) {
		if (H[i-1] == Z[i-1])
			H[i] = min(Z[i-1], Z[i]);
		else
			if (Z[i] < Z[i-1])
				return false;
			else
				H[i] = Z[i-1];
	}
	return true;
}
