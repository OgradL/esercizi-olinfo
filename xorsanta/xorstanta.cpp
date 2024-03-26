#include <iostream>
using namespace std;

int sumxor(int A){
	int v = A % 4;
	if (v == 0)
		return A;
	if (v == 1)
		return 1;
	if (v == 2)
		return A ^ 1;
	if (v == 3)
		return 0;
	return 0;
}

int main() {

	cin.tie(0);
	cin.sync_with_stdio(false);

	int T;
	cin >> T;

	int N, a, b;
	while (T--){
		cin >> N;
		a = b = 0;
		int x = sumxor(N);
		
		for (int i = 0; i < 31 && (1<<i) <= N; i++){
			if (x & (1<<i))
				a += 1<<i;
			else
				a += 1<<i, b += 1<<i;
		}
		cout << a + b << "\n";
	}

	return 0;
}
