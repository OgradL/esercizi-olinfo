#include <bits/stdc++.h>

using namespace std;

bool compare(pair<int, int> a, pair<int, int> b){
	
	
	
}


int main(){
	
	
	int N;
	
	cin >> N;
	
	vector<pair<int, int> > I(N);
	
	int minEnd;
	
	
	for (int i = 0; i < N; i++){
		cin >> I[i].first << I[i].second;
		minEnd = min(minEnd, I[i].second);
	}
	
	
//	sort(I.begin(), I.end(), compare);
	
	
	
	return 0;
}


