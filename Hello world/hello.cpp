#include <bits/stdc++.h>

using namespace std;

int main(){
//	ifstream cin ("input.txt");
//	ofstream cout("output.txt");
	long long N = 0;
	long long H = 0;
	
	string S;
	
	cin >> S;
	
	for (int i = 0; i < S.length(); i++){
		if (S.substr(i,5) == "world"){
			N += H;
		}
		if (S.substr(i,5) == "hello"){
			H++;
		}	
	}
	cout << N << "\n";
	
}
