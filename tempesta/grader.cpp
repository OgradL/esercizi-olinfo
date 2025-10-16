#include <vector>
#include <iostream>
using namespace std;

int atterra(int N, vector<int> U, vector<int> V);

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    int N; cin >> N;

    vector<int> U(N - 1), V(N - 1);
    for(int i = 0; i < N - 1; ++i)
        cin >> U[i] >> V[i];

    cout << atterra(N, U, V) << endl;
}
