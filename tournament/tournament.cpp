#include <iostream>
using namespace std;

int main(){

	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int N;
	cin >> N;

	int m0 = 0, m1 = 0, m = 0, half = 0;
	int i0 = 0, i1 = 0, ib = 0;
	int x;
	for (int i = 0; i < N>>1; i++){
		cin >> x;
		if (x > m0){
			m0 = x;
			i0 = i;
		}
	}

	m = m0;
	ib = i0;
	for (int i = 0; i < N>>1; i++){
		cin >> x;
		if (x > m1){
			m1 = x;
			i1 = i + N/2;
		}
		if (x > m){
			m = x;
			ib = i + N/2;
			half = 1;
		}
	}

	if (half){
		cout << ib << " " << i0 << "\n";
	} else {
		cout << ib << " " << i1 << "\n";
	}

	return 0;
}
