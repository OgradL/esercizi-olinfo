#include <iostream>
#include <vector>

using namespace std;

void pianifica (int N, int K, vector<int> C);

long long viaggia (int l, int r);

int main () {
    
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    
    int N, K;
    cin >> N >> K;

    vector<int> C(N);
    for (int &c: C) cin >> c;
    pianifica(N, K, C);
    
    int Q; cin >> Q;

    for (int i = 0; i < Q; i++) {
        int l, r; 
        cin >> l >> r;
        cout << viaggia(l, r) << endl;
    }
}
