#include <iostream>
#include <unordered_map>
#include <queue>
using namespace std;

int main(){

    int N;
    cin >> N;

    unordered_map<int, priority_queue<int>> g;

    int c, check = 0, ans = 0;
    for (int i = 0; i < N; i++){
        cin >> c;
        if (g[c-2].size() > 0){
            int v = g[c-2].top();
            g[c-2].pop();
            if (v == c) check--;
            else g[c].push(v);
        } else {
            if (c < 0){
                check++;
                ans++;
                g[c].push(-c);
            } else if (c > 0) {
                check = 1e8;
                break;
            } else {
                ans++;
            }
        }
    }

    if (check != 0){
        cout << "0\n";
    } else {
        cout << ans << "\n";
    }

    return 0;
}