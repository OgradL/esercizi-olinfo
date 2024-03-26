#include <iostream>
using namespace std;

int main(){

	cin.tie(0);
	cin.sync_with_stdio(false);

	int N, P;
	cin >> N >> P;

	int mas = 0, bartoli, a1, a2, a3;
	cin >> a1 >> a2 >> a3;
	bartoli = a1 + a2 + a3;
	for (int i = 1; i < N; i++){
		cin >> a1 >> a2 >> a3;
		mas = max(mas, a1 + a2 + a3);
	}


	int b = bartoli - mas;

	cout << max(P * 100 - b + 1, 0) << "\n";

	return 0;
}