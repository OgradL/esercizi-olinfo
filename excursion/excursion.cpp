#include <iostream>
using namespace std;

int main(){

	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int N, K, S;
	cin >> N >> K >> S;

	cout << ((S <= N * K) ? "YES\n" : "NO\n");

	return 0;
}
