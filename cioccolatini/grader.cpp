#include <iostream>
#include <vector>

using namespace std;

vector<int> raccogli(int N, int Q, vector<int> &A, vector<int> &B, vector<int> &C, vector<int> &L, vector<int> &T);

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); 

    int N, Q;
    cin >> N >> Q;

    vector<int> A(N-1), B(N-1);
    for(int i=0; i<N-1; i++){
        cin >> A[i] >> B[i];
    }

    vector<int> C(N);
    for(int i=0; i<N; i++){
        cin >> C[i];
    }
    
    vector<int> L(Q), T(Q);
    for(int i=0; i<Q; i++){
        cin >> L[i] >> T[i];
    }
    
    vector<int> ans = raccogli(N, Q, A, B, C, L, T);

    for(int i=0; i<Q; i++){
        cout << ans[i] << endl;
    }
}
