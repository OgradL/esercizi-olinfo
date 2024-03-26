#include <bits/stdc++.h>

using namespace std;

bool compare(pair<int, int> a, pair<int, int> b){
	return (a.first < b.first);
}



int main(){
	
	int N, K;
	
	cin >> K;
	
	cin >> N;
	
	vector<pair<int, int> > turni(N);
	
	for (int i = 0; i < N; i++){
		cin >> turni[i].first >> turni[i].second;
	}
	
	
	sort(turni.begin(), turni.end(), compare);
	
	
	for (int i = 0; i < N; i++){
		cout << turni[i].first << " " << turni[i].second << "\n";
	}
	
	
	
	
}

