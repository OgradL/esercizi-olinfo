#include <iostream>
#include <vector>
using namespace std;

long long stalkera(int N, int K, vector<int> S);

int main() {
    int N, K;
    cin >> N >> K;

    vector<int> S(N);
    for (auto &s: S) {
        cin >> s;
    }

    cout << stalkera(N, K, S) << '\n';
}
