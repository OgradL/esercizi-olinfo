#include <bits/stdc++.h>
using namespace std;

#define ff endl
#define lf "\n"
#define _ << ' ' <<
#define all(x) begin(x),end(x)
#define rall(x) rbegin(x),rend(x)

#define infor(str, ...) do { fprintf(stderr, str, ##__VA_ARGS__); } while(0)
#define infof(str, ...) do { fprintf(stderr, str"\n", ##__VA_ARGS__); } while(0)

#ifndef DEBUG

#undef infor
#undef infof

#define infor(str, ...)
#define infof(str, ...)

#endif

using ll = long long;

constexpr int LOG = 20;
constexpr int MOD = 1e9+7;
constexpr int MAXN = 1e5+7;

struct DSU {
    DSU(int N): dsu(N, -1), par(N, 0) {}

    int find(int v) {
        if(dsu[v] < 0) return v;

        int rep = find(dsu[v]);

        // breaks rollback :(
        par[v] ^= par[dsu[v]];
        dsu[v] = rep;

        return rep;
    }

    int get_par(int v) {
        if(dsu[v] < 0) return 0; // par[v] == 0

        return par[v] ^ get_par(dsu[v]);
    }

    bool join(int u, int v) {
        int a = u, b = v;
        u = find(u), v = find(v);

        infof("dsu.join(%d, %d): dsu = (%d, %d) | par = (%d, %d)",
            a, b, u, v, get_par(a), get_par(b));

        if(dsu[u] > dsu[v])
            swap(u, v), swap(a, b);

        history.push({u, v, dsu[v], par[v]});

        if(u == v) return get_par(a) != get_par(b);

        dsu[u] += dsu[v];
        dsu[v] = u;

        par[v] = par[a] ^ 1 ^ par[b];

        return 1;
    }

    void rollback(int K = 1) {
        while(K-- > 0) {
            auto [u, v, dsu_v, par_v] = history.top(); history.pop();

            if(u == v) continue;

            par[v] = par_v;
            dsu[v] = dsu_v;
            dsu[u] -= dsu_v;
        }
    }

    void clear(void) {
        rollback(history.size());
    }

    vector<int> dsu;
    vector<int> par;
    stack<array<int, 4>> history;
};

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int N, M; cin >> N >> M;

    vector<array<int, 2>> ed(M);
    for(auto &[u, v]: ed) {
        cin >> u >> v;

        if(u > v)
            swap(u, v);
        u--, v--;
    }

    vector<int> R(M);
    for(int i = 0; i < M; ++i) {
        DSU dsu(N);

        int j = i;
        for(; j < M; ++j) {
            auto [u, v] = ed[j];

            if(!dsu.join(u, v))
                break;
        }

        R[i] = j - i;
    }

    infof("");

    infor("i:");
    for(int i = 0; i < M; ++i)
        infor(" %d", i);
    infof("");

    infor("R:");
    for(auto x: R)
        infor(" %d", x);
    infof("");

    cout << accumulate(all(R), 0LL) << lf;
}
