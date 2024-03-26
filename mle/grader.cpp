#include <bits/stdc++.h>

using namespace std;

void Colora(int N, int Q, vector <int> &A, vector <int> &B, vector <int> &C, vector <int> &murale);

int main(){
  int N, Q;
  cin >> N >> Q;
  vector <int> A(Q, 0), B(Q, 0), C(Q, 0), murale(N, 0);
  for(int i = 0; i < Q; i++){
    cin >> A[i] >> B[i] >> C[i];
  }
  Colora(N, Q, A, B, C, murale);
  for(int i = 0; i < N; i++){
    cout << murale[i] << " ";
  }
  cout << '\n';
  return 0;
}
