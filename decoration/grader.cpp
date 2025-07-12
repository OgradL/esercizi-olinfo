#include <iostream>
#include <vector>

using namespace std;

int decorate(int N, vector<int> F);

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  // If you prefer file IO, uncomment the following two lines.
  //
  // freopen("input.txt", "r", stdin);
  // freopen("output.txt", "w", stdout);

  int N;
  cin >> N;

  vector<int> F(N);
  for (int i = 0; i < N; i++) {
    cin >> F[i];
  }

  cout << decorate(N, F) << endl;

  return 0;
}
