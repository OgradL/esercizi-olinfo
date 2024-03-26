#pragma GCC optimize ("Ofast") 
#pragma GCC optimization ("unroll-loops")
#include <bits/stdc++.h>

using namespace std;

// constraints
#define MAXN 400000

// input data
int N, K, T, i, t;
vector<int> P;

int main() {
    ifstream cin("input.txt");
    ofstream cout("output.txt");
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int N;
    cin >> N;

    vector<int> T(N);
    for (int i=0; i<N; i++)
        cin >> T[i];
    vector<int>preso(N);
    preso[0]=T[0];
    preso[1]=T[1];
    for(int i=2;i<N;i++)
        preso[i]=min(preso[i-1],preso[i-2])+T[i];
    cout << min(preso[N-1],preso[N-2]) << endl; // print the result
    return 0;
}