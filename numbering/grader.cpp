#include <iostream>
#include <variant>
#include <vector>

using namespace std;

variant<bool, vector<pair<int, int>>> find_numbering(int N, vector<int> A);

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);

  int N;
  cin >> N;

  vector<int> A(N);
  for (int i = 0; i < N; i++) {
    cin >> A[i];
  }

  auto result = find_numbering(N, A);
  if (holds_alternative<bool>(result)) {
    if (get<bool>(result)) {
      cout << "YES\n";
    } else {
      cout << "NO\n";
    }
  } else {
    cout << "YES\n";
    cout << (int)get<vector<pair<int, int>>>(result).size() << "\n";
    for (int i = 0; i < (int)get<vector<pair<int, int>>>(result).size(); ++i) {
      cout << get<vector<pair<int, int>>>(result)[i].first << " " << get<vector<pair<int, int>>>(result)[i].second << "\n";
    }
  }

  return 0;
}
