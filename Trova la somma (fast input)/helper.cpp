#include <bits/stdc++.h>

using namespace std;

int main(){
	
	freopen("lol.txt", "w", stdout);
	
	int n;
	
	cin >> n;
	
	cout << "(" << '"';
	
	for (int i = 0; i < n; i++){
		cout << "%d";
	}
	cout << '"';
	
	for (int i = 0; i < n; i++){
		cout << ", &c[" << i << "]";
	}
	cout << ")";
	return 0;
}
