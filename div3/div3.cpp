#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <set>
using namespace std;

#define pb push_back
#define n(s) (s-'0')
#define ll long long


string fix_string(string S, vector<int> pos){
	string news = "";
	int found_sig_digit = 0;
	for(int i = 0; i < S.size(); i++){
		int ok = 1;
		for (int& p : pos)
			ok = ok && (p != i);
		
		if (ok){
			if ((found_sig_digit |= (n(S[i]) > 0)))
				news += S[i];
		}
	}
	if (news.size() == 0)
		news = "-1";
	return news;
}



void solve(){

	string S;
	cin >> S;
	int n = S.size();


	vector<int> moduli(3);
	int modulo_sum = 0;
	for(char i: S){
		moduli[n(i)%3]++;
		modulo_sum += n(i) % 3;
		modulo_sum = modulo_sum % 3;
	}
	
	if(modulo_sum == 0){
		cout << fix_string(S, {}) << "\n";
		return;
	}
	
	// prova a rimuovere una sola cifra
	int m = modulo_sum;
	if (moduli[m] >= 1){
		int last = -1;
		for (int i = 0; i < S.size(); i++){
			if (n(S[i]) % 3 == m){
				if (i == S.size()-1 || (n(S[i]) < n(S[min(int(S.size())-1, i+1)]))){
					cout << fix_string(S, {i}) << "\n";
					return;
				}
				last = i;
			}
		}
		if (!(last == 0 && moduli[3-m] >= 2))
			cout << fix_string(S, {last}) << "\n";
		return;
	}
	m = 3 - modulo_sum;
	if (moduli[m] >= 2){
		vector<int> pos, last_2(2);
		int count = 2, idx = 0;

		for (int i = 0; i < S.size(); i++){
			if (n(S[i]) % 3 == m){
				if ((n(S[i]) < n(S[min(int(S.size())-1, i+1)]))){
					count--;
					pos.pb(i);
					if (count == 0){
						cout << fix_string(S, pos) << "\n";
						return;
					}
				}
				last_2[(idx++)%2] = i;
			}
		}
		cout << fix_string(S, last_2) << "\n";
		return;
	}

	cout << "-1\n";
	return;
}

int main(){
	int T;
	cin >> T;
	while(T--) solve();
	return 0;
}