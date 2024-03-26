//Scrivi qui il tuo codic
#include <iostream>
#include <vector>
using namespace std;

int main() {
    
    int N, K;
    cin >> N;
    
    for (int t = 0; t < N; t++){
        
        cin >> K;
        vector<int> c(10, 0);
        int co = 0, i, n;
        
        for (i = 1; co < 10; i++){
            n = K * i;
            while (n >= 1){
                if (!c[n%10]) co++;
                c[n%10]++;
                n /= 10;
            }
        }
        
        
        
        cout << i - 1 << "\n";
    }
    
    
}