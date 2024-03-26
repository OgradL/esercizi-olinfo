#include <vector>
#include <iostream>
using namespace std;

long long bs(long long lo, long long hi, vector<long long>& dpp, long long por){
    if (lo + 1 >= hi) return lo;
    long long mid = (lo + hi) / 2;

    if (dpp[mid] > por){
        return bs(lo, mid, dpp, por);
    } else if (dpp[mid] <= por){
        return bs(mid, hi, dpp, por);
    }
    return -1;
}


vector<long long> calcola(int T, int M, vector<long long> S, vector<long long> P) {
    vector<long long> R(M);

    vector<long long> dpp(T, 0), dpo(T, 0);

    long long p = 0, o = 0;

    for (int i = 0; i < T; i++){
        p += i * S[i];
        o += S[i];
        dpp[i] = p;
        dpo[i] = o;
    }



    for (long long r = 0; r < M; r++){
        long long por = P[r];

        long long i = bs(0, T, dpp, por);
        if (i == -1) {R[r] = S[0]; continue;}
        if (i >= T - 1) {R[r] = dpo[i]; continue;}
        por = por - dpp[i];

        long long tmp = min(por / (i+1), S[i+1]);
        tmp += dpo[i];

        R[r] = tmp;
    }

    return R;
}
