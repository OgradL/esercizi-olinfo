#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<pair<int, int>> orient_roads(int N, int M, vector<int> A, vector<int> B, vector<int> W);

void wa(string MSG) {
	cout << "Wrong answer: " << MSG << '\n';
	exit(0);
}

void sort_roads(vector<pair<int, int>>& roads) {
  for (auto& road : roads) {
    if (road.first > road.second) swap(road.first, road.second);
  }
  sort(roads.begin(), roads.end());
}

int main() {
  ios_base::sync_with_stdio(false);
  // If you prefer file IO, uncomment the following two lines.
  //
  // freopen("input.txt", "r", stdin);
  // freopen("output.txt", "w", stdout);
  int N, M;
  cin >> N >> M;

  vector<int> A(M), B(M), W(M);
  for (int i = 0; i < M; i++) {
    cin >> A[i] >> B[i] >> W[i];
    int a = A[i], b = B[i];
  }

  auto output_roads = orient_roads(N, M, A, B, W);
  cout << (!output_roads.empty() ? "Yes" : "No") << '\n';
  if (!output_roads.empty()) {
    for (int i = 0; i < output_roads.size(); i++) {
      cout << output_roads[i].first << ' ' << output_roads[i].second << '\n';
    }

    if (output_roads.size() > M) wa("Too many calls to set_road_direction (" + to_string(output_roads.size()) + ")");
    if (output_roads.size() < M) wa("Not enough calls to set_road_direction (" + to_string(output_roads.size()) + ")");
    
    vector<pair<int, int>> actual_roads;
    for (int i = 0; i < M; i++) actual_roads.push_back({A[i], B[i]});
    sort_roads(output_roads);
    sort_roads(actual_roads);

    for (int i = 0; i < M; i++) {
      if (i != 0 && output_roads[i-1] == actual_roads[i]) {
        auto [a,b] = output_roads[i];
        wa("Edge between " + to_string(a) + " and " + to_string(b) + " appears twice");
      }
      if (output_roads[i] != actual_roads[i]) {
        if (!count(actual_roads.begin(), actual_roads.end(), output_roads[i])) {
          auto [a,b] = output_roads[i]; 
          wa("Edge between " + to_string(a) + " and " + to_string(b) + " does not appear in original graph");
        } else {
          auto [a,b] = actual_roads[i]; 
          wa("Edge between " + to_string(a) + " and " + to_string(b) + " does not appear in output graph");
        }
      }
    }
  }

  return 0;
}
