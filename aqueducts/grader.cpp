#include <iostream>
#include <vector>

using namespace std;

vector<int> count(int N, vector<int> S, vector<int> P);

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);

  int N;
  cin >> N;

  vector<int> S(N), P(N);
  for (int i = 0; i < N; i++) {
    cin >> S[i] >> P[i];
  }

  vector<int> C = count(N, S, P);
  for (int i = 0; i < N; i++) {
    cout << C[i] << " \n"[i+1==N];
  }

  return 0;
}
