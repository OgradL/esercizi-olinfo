#include <array>
#include <cassert>
#include <iostream>
#include <utility>
#include <vector>
using namespace std;

array<int, 3> find_plus(int N, int S, int F, vector<int> y, vector<int> x);

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int N, S, F;
    assert(cin >> N >> S >> F);
    vector<int> y(N), x(N);
    for (int i = 0; i < N; i++) {
        assert(cin >> y[i] >> x[i]);
    }
    array<int, 3> ans = find_plus(N, S, F, move(y), move(x));
    cout << ans[0] << " " << ans[1] << " " << ans[2] << "\n";
}
