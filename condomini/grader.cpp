#include <iostream>
#include <vector>
#include <cassert>
using namespace std;

int sbugiarda(int N, vector<int> H);

int main() {
    int N;
    cin >> N;
    vector<int> H(N);
    for (int i = 0; i < N; i++) {
        cin >> H[i];
    }

    int soluzione = sbugiarda(N, H);
    cout << soluzione << "\n";
}
