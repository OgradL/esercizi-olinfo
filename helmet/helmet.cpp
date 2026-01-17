#include <iostream>
#include <numeric>
#include <vector>
using namespace std;

int main(){

	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	srand(time(NULL));

	int N;
	cin >> N;

	vector<long long> X(N), Y(N);
	for (int i = 0; i < N; i++){
		cin >> X[i] >> Y[i];
	}

	vector<int> points(N);
	iota(points.begin(), points.end(), 0);

	auto dist = [&](int a, int b) -> long long {
		long long dx = X[a] - X[b];
		long long dy = Y[a] - Y[b];
		return dx * dx + dy * dy;
	};

	auto choose = [&](vector<int>& points) -> pair<int, int> {
		int it = 0;
		int n = points.size();
		int best = N, A, B;
		while (it < 10){
			int a = rand() % n;
			int b = a;
			while (b == a)
				b = rand() % n;
			a = points[a], b = points[b];

			int cnt_a = 0, cnt_b = 0;
			for (int x : points){
				if (dist(x, a) <= dist(x, b)) cnt_a++;
				else cnt_b++;
			}
			
			if (abs(cnt_a - cnt_b) < best){
				best = abs(cnt_a - cnt_b);
				A = a, B = b;
			}
			it++;
		}
		return {A, B};
	};

	while (points.size() > 1){
		auto [a, b] = choose(points);

		cout << "? " << a << " " << b << "\n" << flush;
		int ret;
		cin >> ret;

		vector<int> new_idx;
		for (int x : points){
			if (ret == 0){
				if (dist(x, a) <= dist(x, b))
					new_idx.push_back(x);
			} else {
				if (dist(x, a) > dist(x, b))
					new_idx.push_back(x);
			}
		}
		swap(points, new_idx);
	}

	cout << "! " << points[0] << "\n" << flush;

	return 0;
}
