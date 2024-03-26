#pragma GCC optimize ("Ofast") 
#pragma GCC optimization ("unroll-loops")
#include <bits/stdc++.h>

using namespace std;

// constraints
#define MAXN 400000

// input data
int N, K, T;
vector<int> P;

int main() {
    //  uncomment the following lines if you want to read/write from files
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    assert(cin >> T);
    
    for(int t = 0; t < T; t++) {
        assert(cin >> N >> K);
        P.resize(N);
        for(i = 0; i < N; i++) {
            assert(cin >> P[i]);
        }
        
        vector<int> open(K,0);
        stack<int> next;
        int result=1;
        for(int i = 0; i < N; i++){
            if(open[P[i]] > 0 && next.top() == P[i]){
                next.pop();
                open[P[i]]--;
            } else {
                open[P[i]]++;
                next.push(P[i]);
            }
        }
        for(int i = 0; i < K; i++){
            if(open[i] > 0){
                result=0;
                break;
            }
        }
        cout << result << "\n";
    }
    return 0;
}
