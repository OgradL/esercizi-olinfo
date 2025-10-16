#include <vector>
#include <iostream>

using namespace std;

int dividi(int N, vector<int> V);

int main(void) {
    int N; cin >> N;

    vector<int> V(N);
    for(auto &x: V) cin >> x;

    cout << dividi(N, V) << endl;
}
