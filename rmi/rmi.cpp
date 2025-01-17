#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(){

	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	long long A, B, N;
	cin >> A >> B >> N;

	vector<long long> day1(N), day2(N);
	for (long long& x : day1)
		cin >> x;

	for (long long& x : day2)
		cin >> x;

	sort(day1.begin(), day1.end());
	sort(day2.begin(), day2.end());

	long long score = A + B;

	int worst = 1;
	int j = 0;
	for (int i = N-1; i >= 0 && j < N; i--){
		while (j < N && day1[i] + day2[j] <= score)
			j++;

		worst += day1[i] + day2[j] > score;
		j++;
	}

	int best = N+1;
	j = N-1;
	for (int i = 0; i < N && j >= 0; i++){
		while (j >= 0 && day1[i] + day2[j] > score)
			j--;

		best -= day1[i] + day2[j] <= score;
		j--;
	}

	cout << best << " " << worst << "\n";

	return 0;
}
