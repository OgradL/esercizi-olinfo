#include <iostream>
using namespace std;

int affetta(int N, int K, string S){
	int ans = 1e9;
	for (int c = 'a'; c <= 'z'; c++){
		int tmp = 0;
		int pos = 0;
		while (pos < N){
			if (S[pos] == c)
				pos++;
			else
				pos += K, tmp++;
		}

		ans = min(ans, tmp);
	}
	return ans;
}
