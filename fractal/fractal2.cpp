#include <bits/stdc++.h>

using namespace std;

#define MODULO 32749

int main() {
	
    long long int N, V, E;

    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    
    cin >> N;
    
    V = 1;
    E = 0;
    long long int newE = E;
    long long int newV = V;
    
    for (int i = 0; i < N; i++){
        newE = V * 3 + (E * 3);
        newV = V * 3 + E * 2;
        E = newE % MODULO;
        V = newV % MODULO;
    }
    
    E %= MODULO;
    V %= MODULO;
    
    cout << V << " " << E << "\n";
    return 0;
}
