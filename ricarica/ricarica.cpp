#include <fstream>
using namespace std;

int main(){

	ifstream cin("input.txt");
	ofstream cout("output.txt");

	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int N, M;
	cin >> N >> M;

	int ans = 1, curr = 0;
	int a, b, last = 0;
	for (int i = 0; i < N; i++){
		cin >> a >> b;
		curr -= a - last - 1;
		ans += max(0, -curr);
		curr = max(curr, 0);
		curr += b - a + 1;
		last = b;
	}

	curr -= M - last;
	ans += max(0, -curr);

	cout << ans << "\n";

	return 0;
}
