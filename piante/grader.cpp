#include <iostream>
#include <vector>

using namespace std;

int pollice_verde(int N, vector<int> H);

int main() {
    int N;
    cin >> N;
    vector<int> H(N);
    for (int& i : H)
        cin >> i;
    cout << pollice_verde(N, H) << '\n';
    return 0;
}
