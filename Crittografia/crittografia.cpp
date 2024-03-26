#include <bits/stdc++.h>

using namespace std;

bool is_int(char c){
	return (int(c) <= 57 && int(c) >= 48);
}

int main(){
	
	#ifdef EVAL
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	#endif
	
	int N, L;
	
	cin >> N >> L;
	
	string S;
	
	cin >> S;
	
	vector<string> password(N, "nope");
	
	for (int i = 0; i < N; i++){
		password[i] = "nope";
	}
	
	bool done = false;
	
	string empty_char = "nope";
	
	for (int i = 0; i < int(L / 2); i++){
		
//		cout << i << "\n";
		
		if (is_int(S[i]) && !is_int(S[L - i - 1])){
			if (password[int(S[i]) - 48].size() > 1 || password[int(S[i]) - 48][0] == S[L - i - 1]){
				password[int(S[i]) - 48] = S[L - i - 1];
			} else {
				done = true;
				cout << "impossibile\n";
				break;
			}
		} else if (!is_int(S[i]) && is_int(S[L - i - 1])){
//			cout << "sd\n";
//			cout << password[int(S[L - i - 1]) - 48] << "\n";
			//cout << "|" << int(password[S[L - i - 1]]) << "|" << int(empty_char[0]) << "| --- " << S[i] << " a " << S[L - i - 1] << "\n";
//			cout << "yess\n";
			if (password[int(S[L - i - 1]) - 48].size() > 1 || password[int(S[L - i - 1]) - 48][0] == S[i]){
				password[int(S[L - i - 1]) - 48] = S[i];
			} else {
				done = true;
				cout << "impossibile\n";
				break;
			}
		}
		
	}
	
	if (!done){
		
		string result = "";
		for (int i = 0; i < N; i++){
			result += password[i];
		}
		
		if (result.size() != N){
			cout << "impossibile\n";
		} else {
			cout << result << "\n";
		}
		
	}
	
	
	return 0;
}
