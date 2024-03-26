#include <iostream>
#include <vector>
#include <queue>
using namespace std;

#define INF (int)(1e9)
#define pb push_back
#define mp make_pair

pair<int, int> dfs(int n, vector<vector<pair<int, int>>>& G, vector<int>& v){
    v[n] = 1;
    
    pair<int, int> ans = {0, n}, t;
    
    for (auto p : G[n])
        if (!v[p.first]){
            t = dfs(p.first, G, v);
            t.first += p.second;
            ans = max(ans, t);
        }
    return ans;
}

int main() {
    
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    
    int N;
    cin >> N;
    
    vector<vector<pair<int, int>>> G(N+1);
    int a, b, p;
    for (int i = 0; i < N-1; i++){
        cin >> a >> b >> p;
        G[a].pb({b, p});
        G[b].pb({a, p});
    }
    
    vector<int> v;
    pair<int, int> ans = {0, 1};
    
    for (int i = 0; i < 5; i++){
        v.assign(N+1, 0);
        ans = dfs(ans.second, G, v);
    }
    
    cout << ans.first << "\n";
    
    return 0;
}