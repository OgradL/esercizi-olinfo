#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <bits/stdc++.h>

#define MAXN 10000

using namespace std;

typedef unsigned long long ull;

vector<int> bob(string& a){
	
	vector<int> sd(a.size());
	
//	int mi = 50;
	
	for (int i = 0; i < a.size(); i++){
		sd[i] = int(a[i]) - 97;
//		mi = min(mi, sd[i]);
	}
	
	vector<int> as(a.size());
	
	as[0] = 0;
	
	cout << "0 ";
	
	for (int i = 1; i < sd.size(); i++){
		
		as[i] = abs(sd[i] - sd[i-1]);
		
		cout << as[i] << " ";
		
//		sd[i] -= mi;
	}
	
	cout << "\n";
	
	return as;
	
}

struct VectorHasher {
    int operator()(const vector<int> &V) const {
        int hash = V.size();
        for(auto &i : V) {
            hash ^= i + 0x9e3779b9 + (hash << 6) + (hash >> 2);
        }
        return hash;
    }
};

int decipher(int N, int D, vector<string> strings) {
    
    //vector<vector<int> > parse(strings.size());
    
    unordered_map<vector<int>, int, VectorHasher> mapp;
    
    //unordered_map<>
    
    int ma = 0;
    
    for (int i = 0; i < strings.size(); i++){
    	vector<int> s = bob(strings[i]);
    	mapp[s]++;
    	ma = max(mapp[s], ma);
	}
    
    
    return ma;
}


int main() {
	
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);
	
    int N, D;
    
    cin >> N >> D;
    
    vector<string> strings(N);
    
    for(int i = 0; i < N; i++) {
        cin >> strings[i];
    }
    
    cout << decipher(N, D, strings);
    return 0;
}

