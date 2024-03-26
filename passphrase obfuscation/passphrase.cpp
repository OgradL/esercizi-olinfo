#include <stdio.h>
#include <iostream>
#include <string>
#include <bits/stdc++.h>

using namespace std;

// input data
int N, K;
string passphrase;

int main() {
//  uncomment the following lines if you want to read/write from files
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

    cin >> N >> K;
    cin >> passphrase;
    
    vector<int> U(N);
    
    for (int i = 0; i < N; i++){
    	U[i] = int(passphrase[i]) - 96;
	}
    
    
    int off = 0;
    for (int i = 0; i < N - 1 - off; i++){
        
        if (off < K){
            if (U[i] < U[i + 1]){
                U.erase(U.begin() + i);
                off++;
                i--;
                if (i >= 0)
                    i--;
            }
        }
        
    }
    
    for (int i = 0; i < N - K; i++){
    	cout << char(U[i] + 96);
	}
    
    
    //cout << passphrase << endl; // print the result
    return 0;
}
