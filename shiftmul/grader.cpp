#include <vector>
#include <algorithm>
using namespace std;

const long long MOD = 2e9 + 7;

long long POW(long long b, long long e){
    if (!e) return 1;
    long long v = POW(b, e/2);
    return (v * v % MOD) * (e&1?b:1) % MOD;
}

long long inv(long long x){
    return POW(x, MOD-2);
}

long long prefproduct(int l, int r, vector<long long>& pref){
    long long ret = pref[r];
    if (l > r){
        ret = (ret * pref.back()) % MOD;
    }
    ret = (ret * inv(pref[l])) % MOD;
    return ret;
}

vector<int> execute(int N, int K, int D, vector<int> A) {
    reverse(A.begin(), A.end());
    vector<long long> B(N);
    
    vector<vector<long long>> prefprod;
    vector<int> v(N, 0);
    int ciclo = 0;
    vector<pair<int, int>> cycle(N, {0, 0});
    for (int i = 0; i < N; i++){
        if (v[i]) continue;
        int idx = i;
        long long prod = 1;
        prefprod.push_back({prod});
        for (int c = 0; !v[idx]; c++){
            v[idx] = 1;
            cycle[idx] = {ciclo, c};
            prod = (prod * A[idx]) % MOD;
            prefprod[ciclo].push_back(prod);
            idx = (idx + D) % N;
        }
        ciclo++;
    }
    
    int len = N / ciclo;
    int exp = K / len;
    int d = K % len;

    for (int i = 0; i < N; i++){
        B[i] = POW(prefprod[cycle[i].first].back(), exp);
        B[i] = (B[i] * prefproduct(cycle[i].second, (cycle[i].second + d) % N, prefprod[cycle[i].first])) % MOD;
    }

    vector<int> ans(N);
    for (int i = 0; i < N; i++){
        ans[i] = B[N-i-1];
    }
    return ans;
}
