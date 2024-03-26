#include <iostream>
#include <vector>
using namespace std;

int main(){

	int N;
	cin >> N;

	vector<int> H(N);
	for (int &n : H) cin >> n;

	long long ans = 0;
	long long seq = 0;
	int num = N-1;
	for (int i = N-2; i >= 0; i--){
		if (H[i] < H[num]){
			seq++;
		} else {
			seq = 0;
			num = i;
		}
		ans = max(ans, seq);
	}

	cout << ans << "\n";

	return 0;
}