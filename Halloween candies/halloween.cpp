#include <iostream>
#include <vector>
using namespace std;

int main(){

	long long N, M;
	cin >> N >> M;

	long long s = 0;
	vector<int> L(N);
	for (int &n : L){
		cin >> n;
		s += s;
	}
	
	long long left = M % s;
	left = s;
	int ans;
	for (int i = 0; i < N && left > 0; i++){
		left -= L[i];
		ans = i;
	}

	cout << ans << "\n";

	return 0;
}