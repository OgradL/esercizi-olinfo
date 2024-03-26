/*
 * This template is valid both in C and in C++,
 * so you can expand it with code from both languages.
 * NOTE: it is recommended to use this even if you don't
 * understand the following code.
 */

#include <bits/stdc++.h>

using namespace std;

// constraints
#define MAXN 100000

// input data
int N, i;
vector<int> P, T;

int main() {
//  uncomment the following lines if you want to read/write from files
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	int maxP = 0;
	cin >> N;
	P.resize(N);
	T.resize(N);
    for(i=0; i<N; i++){
        cin >> P[i];
        maxP = max(maxP, P[i]);
	}
    for(i=0; i<N; i++)
        cin >> T[i];
    
    
    vector<int> maximum(maxP + 1, 0);
	
	
    int total = 0;
    for (int i = 0; i < N; i++){
    	total += T[i];
    	maximum[P[i]] = max(maximum[P[i]], T[i]);
	}
	
    int timeSaved = accumulate(maximum.begin(), maximum.end(), 0);
    total -= timeSaved;
    
    cout << total << "\n";
    return 0;
}
