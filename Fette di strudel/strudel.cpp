#include <stdio.h>
#include <assert.h>
#include <bits/stdc++.h>

using namespace std;

#define MAXN 100000

int porziona(int N, vector<int>& mandorle, vector<int>& cannella) {
    
    vector<int> diff(N);
    
    for (int i = 0; i < N; i++){
    	diff[i] = cannella[i] - mandorle[i];
	}
    
    
    vector<int> pref(N);
    int sum = 0;
	for (int i = 0; i < N; i++){
    	sum += diff[i];
    	pref[i] = sum;
	}
    
    
    vector<int> tagli_len;
    vector<int> tagli_sum;
    
	tagli_len.push_back(0);
	tagli_sum.push_back(0);
    
    int ans = 0;
    
    for (int i = 0; i < N; i++){
    	int co = -pref[i];
    	if (co > tagli_sum.back()){
    		tagli_len.push_back(i+1);
    		tagli_sum.push_back(co);
		}
		
		int need = co;
		auto it = lower_bound(tagli_sum.begin(), tagli_sum.end(), need);
		int idx = it - tagli_sum.begin();
		int lt = tagli_len[idx];
		int len = i + 1 - lt;
		ans = max(len, ans);
	}
	
    //cout << s << " " << e << "\n";
    return ans;
}


int main() {
    
    int N;
    
    #ifdef EVAL
    	freopen("input.txt", "r", stdin);
    	freopen("output.txt", "w", stdout);
    #endif
    
    cin >> N;
    
    vector<int> mandorle(N);
    vector<int> cannella(N);
    
    for(int i = 0; i < N; i++)
        cin >> mandorle[i];
    for(int i = 0; i < N; i++)
        cin >> cannella[i];
    
    cout << porziona(N, mandorle, cannella);
    return 0;
}
