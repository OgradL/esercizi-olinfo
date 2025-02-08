#include <iostream>
#include <vector>
using namespace std;

int main(){

	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int N;
	cin >> N;

	vector<int> ans(10, 0);

	for (int i = 1; i <= N; i++){
		int p = 1;
		while (p <= i){
			ans[(i/p)%10]++;
			p *= 10;
		}
	}

	for (int x : ans)
		cout << x << ' ';
	cout << "\n";

	return 0;
}
