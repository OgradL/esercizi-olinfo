//Scrivi qui il tuo codice
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

#define ll long long
#define MOD 666013

int main(){
    
    int N;
    cin >> N;
    
    vector<int> V(N);
    for (int &i: V) cin >> i;
    
    sort(V.begin(), V.end());
    
    ll ans = 1, add = 1;
    
    for (int i = 1; i < N; i++){
        if (V[i] != V[i-1]) add++;
        ans += add;
    }
    
    cout << ans << "\n";

    return 0;
}