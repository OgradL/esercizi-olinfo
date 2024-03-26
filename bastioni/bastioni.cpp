#include <iostream>
#include <string>
#include <vector>
#include <queue>
using namespace std;

int arrampicate(int N, string S){

	for (int i = 1; i < N; i++){
		if (S[i] == '?'){
			if (S[i-1] == '<'){
				
			}
			if (S[i-1] == '>'){
				
			}
		}
	}

	vector<int> prefdx(N+1), prefsx(N+1);

	prefdx[N] = N;
	for (int i = N-1; i >= 0; i--){
		if (S[i] == '>' || S[i] == '=')
			prefdx[i] = prefdx[i+1];
		else
			prefdx[i] = i;
	}

	prefsx[0] = 0;
	for (int i = 1; i <= N; i++){
		if (S[i-1] == '<' || S[i-1] == '=')
			prefsx[i] = prefsx[i-1];
		else
			prefsx[i] = i;
	}

	vector<int> prefsxinv(N+1, 0);
	for (int i = N; i >= 0; i--){
		prefsxinv[prefsx[i]] = max(prefsxinv[prefsx[i]], i);
	}
	for (int i = 0; i <= N; i++){
		prefsxinv[i] = prefsxinv[prefsx[i]];
	}
	
	int pos = -1, step = 0, last = -1, curr;
	while (pos < N){
		pos++;
		step += 1;
		pos = max(prefdx[pos], prefsxinv[pos]);
	}

	return step;
}
