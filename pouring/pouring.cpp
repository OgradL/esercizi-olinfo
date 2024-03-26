#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>
using namespace std;

int main(){

	long long Ac, Bc;
	cin >> Ac >> Bc;
	long long As, Bs;
	cin >> As >> Bs;
	long long Ag, Bg;
	cin >> Ag >> Bg;

	unordered_map<long long, unordered_map<long long, long long>> v;
	queue<pair<pair<long long, long long>, pair<long long, long long>>> q;
	q.push({{As, Bs}, {0, 0}});
	q.push({{Ag, Bg}, {0, 1}});
	pair<pair<long long, long long>, pair<long long, long long>> p;
	long long A, B, t;
	int type;
	while (!q.empty()){
		p = q.front();
		A = p.first.first;
		B = p.first.second;
		t = p.second.first;
		type = p.second.second;
		q.pop();

		if (A == As && B == Bs && t < 0){
			t = abs(t);
			break;
		}
		if (A == Ag && B == Bg && t > 0){
			t = abs(t);
			break;
		}
		if (v[A][B] * t < 0){
			t = abs(t) + abs(v[A][B]);
			break;
		}

		if (v[A][B] * t > 0)
			continue;
		v[A][B] = t;

		int delta = -type * 2 + 1;

		if (type == 0){
			if (A)
				q.push({{0, B}, {t+delta, type}});
			
			if (B)
				q.push({{A, 0}, {t+delta, type}});

			if (A != Ac)
				q.push({{Ac, B}, {t+delta, type}});
			
			if (B != Ac)
				q.push({{A, Bc}, {t+delta, type}});
			
			int k = min(Ac - A, B);
			if (k)
				q.push({{A + k, B - k}, {t+delta, type}});

			k = min(A, Bc - B);
			if (k)
				q.push({{A - k, B + k}, {t+delta, type}});
		}
		if (type == 1){
			
		}

	}

	cout << t << "\n";

	return 0;
}