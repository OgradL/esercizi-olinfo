#include <iostream>
#include <vector>

using namespace std;

int squalifica(int N, vector<int> T, vector<int> L);

int main() {
    int N;
    cin >> N;

    vector<int> T(N), L(N);

    for (int &i : T)
        cin >> i;
    for (int &i : L)
        cin >> i;

    cout << squalifica(N, T, L) << endl;
}
