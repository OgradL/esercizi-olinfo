#include <cmath>
#include <iostream>
#include <vector>
using namespace std;

int main(){

	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
	int N, M;
	cin >> N >> M;

	vector<vector<long long>> table(N, vector<long long>(M));

	vector<pair<int, int>> knowns;

	for (int i = 0; i < N; i++){
		for (int j = 0; j < M; j++){
			string s;
			cin >> s;

			if (s == "?"){
				table[i][j] = -1;
			} else {
				table[i][j] = stoll(s);
				knowns.push_back({i, j});
			}
		}
	}

	if (knowns.size() == 0){
		cout << "YES\n";
		return 0;
	}

	if (knowns.size() == 1){

		auto [i, j] = knowns[0];
		long long v = table[i][j];
		++i, ++j;

		int ok = 0;
		for (long long d = min(i, j); d * d <= v; d++){
			if (v % d)
				continue;

			if (v / d >= max(i, j)){
				ok = 1;
				break;
			}
		}

		if (ok){
			cout << "YES\n";
		} else {
			cout << "NO\n";
		}

		return 0;
	}

	auto try_sol = [&](int real_i, int real_j, int prev_i, int prev_j) -> bool {
		if (real_i <= 0 || real_j <= 0)
			return false;
		for (int i = 0; i < N; i++){
			for (int j = 0; j < M; j++){
				long long x = i - prev_i + real_i;
				long long y = j - prev_j + real_j;
				if (table[i][j] >= 0 && table[i][j] != x * y){
					return false;
				}
			}
		}
		return true;
	};


	if (knowns[0].second > knowns[1].second)
		swap(knowns[0], knowns[1]);

	auto [i0, j0] = knowns[0];
	auto [i1, j1] = knowns[1];

	long long A = table[i0][j0];
	long long B = table[i1][j1];

	int a = i1 - i0;
	int b = j1 - j0;

	if (a == 0){

		long long real_i = (B - A) / b;
		if ((B - A) % b != 0){
			cout << "NO\n";
			return 0;
		}

		int real_j = A / real_i;

		if (try_sol(real_i, real_j, i0, j0)){
			cout << "YES\n";
			return 0;
		} else {
			cout << "NO\n";
			return 0;
		}
	}

	if (b == 0){

		long long real_j = (B - A) / a;
		if ((B - A) % a != 0){
			cout << "NO\n";
			return 0;
		}

		int real_i = A / real_j;

		if (try_sol(real_i, real_j, i0, j0)){
			cout << "YES\n";
			return 0;
		} else {
			cout << "NO\n";
			return 0;
		}
	}

	long long t = a*b + A - B;

	long long D = t * t - 4 * a * b * A;

	if (D < 0){
		cout << "NO\n";
		return 0;
	}

	long long rootD = sqrt(D);
	if (rootD * rootD != D){
		cout << "NO\n";
		return 0;
	}

	long long x0 = (- t + rootD) / (2 * b);
	long long x1 = (- t - rootD) / (2 * b);
	
	long long y0 = A / x0;
	long long y1 = A / x1;

	if (try_sol(x0, y0, i0, j0) || try_sol(x1, y1, i0, j0)){
		cout << "YES\n";
		return 0;
	} else {
		cout << "NO\n";
		return 0;
	}

	return 0;
}
