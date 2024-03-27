#include <ios>
#include <iostream>
#include <vector>
using namespace std;

long long comunica(int N, int M, int K, int S, int E, vector<int> A, vector<int> B, vector<int> T, vector<int> D);

int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(0);

    int N, M, K, S, E;
    cin >> N >> M >> K >> S >> E;

    vector<int> A(M), B(M), T(M), D(M);
    for(int i = 0; i < M; ++i){
        cin >> A[i] >> B[i] >> T[i] >> D[i];
    }

    cout << comunica(N, M, K, S, E, A, B, T, D) << endl;
    return 0;
}
