#include <algorithm>
#include <utility>
#include <vector>
#include <iostream>
using namespace std;

pair<vector<int>, vector<int>> disegna(int N, long long C, long long D){

	vector<int> X, Y;

	// C
	vector<pair<int, int>> xx;
	for (int i = 0; i < 2*N; i += 2){
		xx.push_back({i, min(1 + i, 2*N - i - 1)});
	}

	sort(xx.begin(), xx.end(), [&](const pair<int, int>& a, const pair<int, int>& b){
		return a.second > b.second;
	});

	for (auto [idx, len] : xx){
		if (len <= C){
			C -= len;
			X.push_back(idx);
		}
	}


	// D
	vector<pair<int, int>> yy;
	for (int i = N-1; i > -N; i -= 2){
		yy.push_back({i, min(abs(N-i), abs(N+i))});
	}

	sort(yy.begin(), yy.end(), [&](const pair<int, int>& a, const pair<int, int>& b){
		return a.second > b.second;
	});

	for (auto [idx, len] : yy){
		if (len <= D){
			D -= len;
			Y.push_back(idx);
		}
	}

	return {X, Y};
}


// GRADER DI ESEMPIO
// NON MODIFICARE AL DI SOTTO DI QUESTA LINEA

#ifndef EVAL
int main() {
    ios_base::sync_with_stdio(false);

    int N;
    long long C, D;

    cin >> N >> C >> D;

    auto [crescenti, decrescenti] = disegna(N, C, D);

    for (int c: crescenti)
        cout << c << ' ';
    cout << '\n';

    for (int d: decrescenti)
        cout << d << ' ';
    cout << '\n';
}
#endif
