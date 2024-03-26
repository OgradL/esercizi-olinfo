#include <bits/stdc++.h>

using namespace std;

int main() {
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);
    ios_base::sync_with_stdio(false);

    int N, R, C;
    cin >> N >> R >> C;
    
    long long left = C;
    long long right = R - C + 1;
    
    long long answer = left * right;
    
    cout << answer << "\n";
    
}

