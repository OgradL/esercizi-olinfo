#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> pairi;

bool intersect(pairi& a, pairi& b, pairi& c){
	
	if (a.first == b.first){
		if (c.first == a.first && c.second <= max(a.second, b.second) && c.second >= min(a.second, b.second)) return true;
	} else if (a.second == b.second){
		if (c.second == a.second && c.first <= max(a.first, b.first) && c.first >= min(a.first, b.first)) return true;
	}
	
	return false;
}

int main(){
	
	
	int N, M;
	
	cin >> N >> M;
	
	vector<pairi> p(N + 1);
	vector<pairi> f(M);
	
	int a, b;
	for (int i = 0; i <= N; i++){
		cin >> a >> b;
		p[i] = make_pair(a, b);
	}
	for (int i = 0; i < M; i++){
		cin >> a >> b;
		f[i] = make_pair(a, b);
	}
	
	
	
	return 0;
}
