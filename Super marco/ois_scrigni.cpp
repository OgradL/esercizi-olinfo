#include <bits/stdc++.h>

using namespace std;

int main() {
    
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    
    long long int n;
    cin >> n;
    
	long long int scosse = (n * (n - 1)) / 4;
    
    if ((n * (n - 1)) % 4 == 0)
        cout << scosse;
    else
        cout << scosse << ".5";
	
		
	return 0;
}
