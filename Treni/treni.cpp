#include <iostream>
#include <vector>

using namespace std;

int f(int pos, int fin, int N, vector<int>& A, vector<int>& B, vector<vector<int>>& memo){
    if (pos >= N) return 0;
    if (memo[pos][fin + 1] >= -1) return memo[pos][fin + 1];
    
    int ans = f(pos + 1, 0, N, A, B, memo);
    
    if (fin == -1){
        ans = max(ans, f(pos + 1, 1, N, A, B, memo));
    }
    
    ans = max(ans, f(pos + 1, -1, N, A, B, memo));
    
    int add = 0;
    
    if (fin == 0) add = A[pos];
    else if (fin == 1) add = B[pos];
    
    memo[pos][fin + 1] = ans + add;
    return memo[pos][fin + 1];
}

int tempo_massimo(int N, int a[], int b[])
{
    
    vector<int> A(N), B(N);
    
    for (int i = 0; i < N; i++){
        A[i] = a[i];
        B[i] = b[i];
    }
    
    vector<vector<int>> memo(N, vector<int>(3, -2));
    
    int ans = f(0, 0, N, A, B, memo);
    
    ans = max(ans, f(0, 1, N, A, B, memo));
    
    ans = max(ans, f(0, -1, N, A, B, memo));
    
    return ans;
}