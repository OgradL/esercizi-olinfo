#include <iostream>
#include <vector>
using namespace std;

int componi(int N, int J, vector<int> F);

int main() {

    int N, J;
    cin >> N >> J;

    vector<int> F(N);
    for (int &f: F) cin >> f;

    cout << componi(N, J, F) << endl;
}
