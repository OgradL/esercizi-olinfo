#include <iostream>
using namespace std;

int main(){

	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int N;
	cin >> N;

	string L, R;
	cin >> L >> R;

	int i = 0;

	while (i < N && (L[i] == 'G' || R[i] == 'G'))
		i++;

	cout << i << "\n";

	return 0;
}
