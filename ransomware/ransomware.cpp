#include <iostream>
#include <vector>
using namespace std;

string solve(string code, vector<string>& codes){
    //cout << code << "\n";
    string res = "", tmp;
    for (int i = 0; i < 10; i++){
        if (code.size() < codes[i].size())
            continue;
        if (code.substr(0, codes[i].size()) == codes[i]){
            //cout << code << " " << i << " " << codes[i] << "\n";
            tmp = to_string(i) + solve(code.substr(codes[i].size(), code.size()-codes[i].size()), codes);
            if (tmp.size() > res.size())
                res = tmp;
        }
    }
    
    return res;
}

int main() {
    
    cin.tie(0);
    cin.sync_with_stdio(false);
    
    cout.tie(0);
    cout.sync_with_stdio(false);
    
    int N;
    cin >> N;
    
    vector<string> codicis(N);
    for (int i = 0; i < N; i++){
        cin >> codicis[i];
    }
    
    vector<string> codes(10);
    for (auto &s : codes)
        cin >> s;
    
    
    for (int i = 0; i < N; i++){
        cout << solve(codicis[i], codes) << "\n";
    }
    
    return 0;
}