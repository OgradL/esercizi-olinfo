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

	

	cout << "-1\n";
	return;
}

int main(){
	int T;
	cin >> T;
	while(T--) solve();
	return 0;
}