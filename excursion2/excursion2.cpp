#include <iostream>
using namespace std;

int main(){
	
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int A, F, M;
	cin >> A >> F >> M;

	cout << 2 * M + 3 * F + A << "\n";
	cout << 1 * M + 1 * F + A << "\n";


	return 0;
}
