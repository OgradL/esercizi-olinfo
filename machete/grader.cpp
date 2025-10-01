#include <vector>
#include <iostream>

using namespace std;

int machete(int N, int K, vector<int> P);

int main() {

    int N, K;
    cin >> N >> K;
    vector<int> P(N);
    for(auto &i : P) cin >> i;

    cout << machete(N, K, P) << endl;
}   
