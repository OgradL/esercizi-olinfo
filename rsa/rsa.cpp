#pragma GCC optimize ("Ofast") 
#pragma GCC optimization ("unroll-loops")
#include <cmath>

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

ll fast_mod_pow(ll N, ll D, ll M){
	
	if (D == 0){
		return 1;
	}
	if (D == 1){
		return N % M;
	}
	
	if (D % 2 == 0){
		ll num = fast_mod_pow(N, D / 2, M);
		return (num * num) % M;
	} else {
		ll num = fast_mod_pow(N, D - 1, M);
		return (N * num) % M;
	}
	
}

void decifra(int N, int d, int L, int* messaggio, char* plaintext) {
    ll current = 0;
    ll current2 = 0;
    for (int j = 0; j < L; j++){
        current = 1;
        current2 = messaggio[j] % N;
        current = fast_mod_pow(current2, d, N);
        plaintext[j] = (char)current;
    }
    
    
    plaintext[L] = '\0';
    //for (int k = 0; k < L; k++)
        //cout << text[k];
    
    
}
