//Scrivi qui il tuo codice
#include <iostream>
#include <vector>

using namespace std;

int main() {
    
    int N;
    cin >> N;
    
    vector<int> H(N);
    for (int &i : H) cin >> i;
    
    int ans = 0;
    vector<int> v(N, -1);
    for (int i = 0; i < N; i++){
        if (v[i] > -1) continue;
        int h = i, num = 0;
        while (v[h] == -1){
            num++;
            v[h] = num;
            h = H[h];
        }
        
        ans = max(ans, num - v[h] + 1);
        
    }
    
    cout << ans << "\n";
    return 0;
}