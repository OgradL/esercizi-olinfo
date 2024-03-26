#include <bits/stdc++.h>
#define con(x) (cerr << __LINE__ << ": " << #x << ' ' << (x) << endl, (x))
#define vis() (cerr << __LINE__ << endl)
#define ll long long
#define f first
#define s second
#define pb push_back
#define rsz resize
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()

using namespace std;


int main(){

	int N;
	
	cin >> N;

	int a = (N+1)/2;

	for (int i = 0; i < a; i++){
		cout << "1 0 1\n";
	}
	cout << (N - a) << " 0 1\n";

	for (int i = 0; i < N - a; i++){
		cout << "1 1 0\n";
	}
	cout << (N - a) << " 0 1\n";

	return 0;
}

