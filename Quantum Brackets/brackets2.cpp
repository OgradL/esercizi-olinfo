#pragma GCC optimize ("Ofast") 
#pragma GCC optimization ("unroll-loops")
#include <cassert>
#include <iostream>
#include <bits/stdc++.h>
#include <stdio.h>

// constraints
#define MAXN 400000

using namespace std;

// input data
int N, K, T;
vector<int> P;

int main() {
    
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
	
    assert(cin >> T);
    for(int t = 0; t < T; t++) {
        assert(cin >> N >> K);
        P.resize(N);
        for(int i = 0; i < N; i++) {
            assert(cin >> P[i]);
        }
        
        vector<int> open;
        open.resize(K + 1);
        bool good = true;
        int pos = -1;
        
        for (int i = 0; i < N && good; i++){
        	
        	if (pos >= 0){
            	if (open[pos] == P[i]){
            		pos--;
				} else {
					pos++;
					open[pos] = P[i];
				}
        	} else {
				pos++;
				open[pos] = P[i];
			}

        }
        
        if (pos >= 0){
        	good = false;
		}
        
        if (good){
            cout << "1\n";
        } else {
            cout << "0\n";
        }
        
    }
    return 0;
}

