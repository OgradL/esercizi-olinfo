#include <bits/stdc++.h>

using namespace std;

bool palindroma(int i, int j, string S){
	
	string pali;
	
	pali = S.substr(i, j);
	
//	cout << pali << "\n";
	
	int N = pali.size();
	
	for (int i = 0; i < N; i++){
		if (pali[i] != pali[N - i - 1]){
//			cout << pali << " no\n";
			return false;
		}
	}
//	cout << pali << " si\n";
	return true;
}

int main(){
	
	string S;
	
	cin >> S;
	
	int N = S.size();
	
	vector<vector<string> > map(N, vector<string>(N));
	
	int ans = 1;
	
	for (int i = 0; i < N; i++){
		for (int j = i; j < N; j++){
			bool good = palindroma(i, j, S);
			if (!good){
//				break;
			} else {
				string sub;
				sub = S.substr(i, j);
				int siz = sub.size();
				ans = max(ans, siz);
			}
		}
	}
	
	cout << "\n\n\n" << ans << "\n";
	
	return 0;
}
