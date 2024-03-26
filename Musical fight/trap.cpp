#include <bits/stdc++.h>

using namespace std;

// input data
int N, L;

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    ios::sync_with_stdio(false);
    cin.tie(0);

    unordered_map <std::string, int> mp;
    vector<std::string> s0;
    cin >> N >> L;

    int M;
    cin >> M;
    for (int j = 0; j < M; ++j) {
        string s;
        cin >> s;
        s0.push_back(s);
    }

    for (int i = 1; i < N; i++) {
        cin >> M;
        unordered_set<std::string> strSet;
        string s;

        for (int j = 0; j < M; j++) {
            cin >> s;
            strSet.insert(s);
        }

        for (auto it = strSet.begin(); it != strSet.end(); ++it) {
            mp[*it]++;
        }
    }

    for (size_t i = 0; i < s0.size(); i++) {
        cout << mp[s0[i]] << " ";
    }

    return 0;
}