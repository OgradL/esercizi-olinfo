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
int N, K, T, i, t;
vector<int> P;

int main() {
    
//	freopen("input0.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
	
    assert(cin >> T);
    for(t = 0; t < T; t++) {
        assert(cin >> N >> K);
        P.resize(N);
        for(i = 0; i < N; i++) {
            assert(cin >> P[i]);
        }
        
        stack<int> open;
        //isOpen.resize(K);
        bool good = true;
        //int currentBracket = 0;
        //int bigIndex = 0;
        
        for (i = 0; i < N && good; i++){
        	
        	if (open.size() != 0){
            	if (open.top() == P[i]){
            		open.pop();
				} else {
					open.push(P[i]);
				}
        	} else {
				open.push(P[i]);
			}
			
        	/*if (open.size() != 0){
            	if (P[i] > open.top()){
            		open.push(P[i]);
				} else if (P[i] == open.top()){
					open.pop();
				}else{
					good = false;
					break;
				}
			}else{
				open.push(P[i]);
			}*/	
            
        }
        
        if (open.size() != 0){
        	good = false;
		}
        
        if (good){
            cout << "1\n";
        } else {
            cout << "0\n";
        }
        
        
        //cout << 42 << endl; // print the result
    }
    return 0;
}

