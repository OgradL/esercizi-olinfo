#include <algorithm>
#include <cstdlib>
#include <iostream>
#include <numeric>
#include <vector>

using namespace std;

bool chiedi(vector<int> S, int x);

const double phi = 0.618033989;

int delibera(int N) {

	auto rec = [&](auto&& rec, int l, int r, vector<int>& available) -> int {
		int m = l + (r - l) * phi;

		vector<int> sl, sr;
		for (int i = l; i < r; i++){
			if (i < m)
				sl.push_back(i);
			else
				sr.push_back(i);
		}

		vector<int> left_colors, right_colors;
		int cnt = 0;
		for (int c : available){
			if (chiedi(sl, c)){
				cnt++;
				left_colors.push_back(c);
			} else {
				right_colors.push_back(c);
			}
		}

		if (cnt != m - l){
			return rec(rec, l, m, left_colors);
		}

		for (int c : left_colors){
			if (chiedi(sr, c))
				return c;
		}

		return rec(rec, m, r, right_colors);
	};

	vector<int> colors(N);
	iota(colors.begin(), colors.end(), 0);

	return rec(rec, 0, N+1, colors);
}

// GRADER DI ESEMPIO, NON MODIFICARE

#ifndef EVAL

namespace {
int N;
vector<int> A;
int queries = 0;
}  // namespace

bool chiedi(vector<int> S, int x) {
    queries++;
    if (x < 0 || x >= N) {
        cout << "Invalid query" << endl;
        exit(0);
    }
    sort(S.begin(), S.end());
    if (!S.empty() && (S.front() < 0 || S.back() >= N + 1)) {
        cout << "Invalid query" << endl;
        exit(0);
    }
    if (unique(S.begin(), S.end()) != S.end()) {
        cout << "Invalid query" << endl;
        exit(0);
    }

    for (int idx : S)
        if (A[idx] == x) return true;
    return false;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;

    for (int tc = 0; tc < T; ++tc) {
        cin >> N;

        A.assign(N + 1, 0);
        for (int i = 0; i < A.size(); ++i) {
            if (!(cin >> A[i])) {
                cout << "Invalid instance" << endl;
                return 0;
            }
        }

        if (N <= 0) {
            cout << "Invalid instance" << endl;
            return 0;
        }
        vector<int> freq(N, 0);
        for (int v : A) {
            if (v < 0 || v >= N) {
                cout << "Invalid instance" << endl;
                return 0;
            }
            freq[v]++;
        }

        int expected_value = -1;
        int twice = 0;
        for (int v = 0; v < N; ++v) {
            if (freq[v] == 2) {
                twice++;
                expected_value = v;
            } else if (freq[v] != 1) {
                cout << "Invalid instance" << endl;
                return 0;
            }
        }
        if (twice != 1) {
            cout << "Invalid instance" << endl;
            return 0;
        }

        queries = 0;

        int got = delibera(N);

        if (got != expected_value)
            cout << "Wrong answer" << endl;
        else
            cout << "Correct. " << queries << " queries." << endl;
    }

    return 0;
}

#endif
