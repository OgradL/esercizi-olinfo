// NOTE: it is recommended to use this even if you don't understand the following code.

#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

// input data
int N;
long long M, L;
vector<long long> D;

int main() {
//  uncomment the following lines if you want to read/write from files
//  ifstream cin("input.txt");
//  ofstream cout("output.txt");

    cin >> N >> M >> L;
    D.resize(N);
    for (int i=0; i<N; i++)
        cin >> D[i];

    // insert your code here

    cout << 42 << endl; // print the result
    return 0;
}
