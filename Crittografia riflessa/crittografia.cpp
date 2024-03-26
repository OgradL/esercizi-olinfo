#include <bits/stdc++.h>

using namespace std;

int main(){
	
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	
	string a;
	
	cin >> a;
	
	string b = a;
	
	int len = a.length();
	
	for (int i = 0; i < len; i++){
	    b[i] = a[len - i - 1];
	}
	
	int ans;
	
	int op1 = stoi(a);
	int op2 = stoi(b);
	
	ans = op1 + op2;
	
	cout << ans << "\n";
	
	return 0;
}
