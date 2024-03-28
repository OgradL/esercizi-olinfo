#include <iostream>
#include <vector>

using namespace std;

int somma(int n) {
    int sum = 0;

    do {
        sum += n % 10;
    } while (n /= 10);

    return sum;
}

int codifica(int n) {
    int res = n;
    while (n > 9) {
        int sum = somma(n);
        res += sum;
        n = sum;
    }
    return res;
}

int main() {
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	ios_base::sync_with_stdio(false);

	int min, max, inizio = 0;
	cin >> min;
	cin >> max;
	if (min >= 102) {
		inizio = min - 102;
	}

	pair<int, int> ress[1000000];

	for (int i = inizio; i <= max; i++) {
		int res = codifica(i);
		if (res - min >= 0 && res - min <= 1000000) {
			ress[res - min].first = i;
			ress[res - min].second++;
		}
	}

	for (int i = 0; i <= max - min; i++) {
		if (ress[i].second == 1) {
			cout << ress[i].first << "\n";
		} else if (ress[i].second > 1) {
			cout << "AMBIGUOUS\n";
		} else {
			cout << "IMPOSSIBLE\n";
		}
	}
}