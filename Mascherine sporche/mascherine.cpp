#include <vector>
using namespace std;

void riprogramma(int N, int K, vector<int>& C) {
	for (int i = 1; i < N; i++) {
		
		if (i == 0){
			
			if (C[i] == C[i + 1]){
				for (int j = 1; j <= K; j++)
					if (j != C[i + 1]){
						C[i] = j;
						break;
					}
			
			
		} else if (i == N - 1){
			
			if (C[i] == C[i - 1]){
				for (int j = 1; j <= K; j++)
					if (j != C[i - 1]){
						C[i] = j;
						break;
					}
			}
			
			
		} else {
			
			if (C[i] == C[i - 1] || C[i] == C[i + 1]){
				for (int j = 1; j <= K; j++)
					if (j != C[i - 1] && j != C[i + 1]){
						C[i] = j;
						break;
					}
			}
			
		}
	}
	
	return C;
	
}
