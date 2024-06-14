#include <iostream>
#include <vector>
#include <variant>

using namespace std;

variant<bool, vector<int>> find_tour(int N, vector<int> A);

int main() {
  ios_base::sync_with_stdio(false);
  // If you prefer file IO, uncomment the following two lines.
  //
  // freopen("input.txt", "r", stdin);
  // freopen("output.txt", "w", stdout);

  int N;
  cin >> N;

  vector<int> A(N);
  for (int i = 0; i < N; i++) {
    cin >> A[i];
  }

  auto result = find_tour(N, A);
  if (holds_alternative<bool>(result)) {
    if (get<bool>(result)) {
      cout << "YES" << endl;
    }
    else {
      cout << "NO" << endl;
    }
  }
  else {
    cout << "YES" << endl;
    bool good = (int)get<vector<int>>(result).size() == N;
    if (good) {
      for (int i=0; i < N; ++i) {
        if (i > 0) cout << " ";
        cout << get<vector<int>>(result)[i];
      }
      cout << endl;
    }
  }

  return 0;
}
