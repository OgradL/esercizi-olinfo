#include <iostream>

using namespace std;

long long compute(long long n);

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
	long long n;
	cin >> n;
	cout << compute(n) << "\n";
	
	return 0;
}
