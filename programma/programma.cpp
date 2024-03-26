#include <iostream>
#include <string>
#include <vector>
using namespace std;

pair<int, int> D[4] = {{1, 0}, {0, -1}, {-1, 0}, {0, 1}};

pair<int, int> operator+(pair<int, int> a, pair<int, int> b){
	return {a.first + b.first, a.second + b.second};
}
pair<int, int> operator-(pair<int, int> a, pair<int, int> b){
	return {a.first - b.first, a.second - b.second};
}

int main(){

	int N, M;
	cin >> N >> M;

	string P;
	cin >> P;

	vector<pair<int, int>> pref(N+1, {0, 0});
	vector<int> last_x(N);
	int l = -1;
	pref[0] = {0, 0};
	int dir = 0;
	for (int i = 1; i <= N; i++){
		pref[i] = pref[max(0, i - 1)];
		if (P[i-1] == 'F'){
			pref[i] = pref[max(0, i - 1)] + D[dir];
		}
		if (P[i-1] == 'B'){
			pref[i] = pref[max(0, i - 1)] - D[dir];
		}
		if (P[i-1] == 'R'){
			dir = (dir + 1) % 4;
		}
		if (P[i-1] == 'L'){
			dir = (dir + 3) % 4;
		}
		if (P[i-1] == 'X'){
			l = i-1;
		}
		last_x[i] = l;
	}
	
	// oh no i forgot the orientation

	pair<int, int> pos = {0, 0};
	int S, E;
	while (M--){
		cin >> S >> E;
		E++;

		if (last_x[E] >= S){
			P.substr(S, E).find('X');
		} else {
			pos = pos + pref[E] - pref[S];
		}


	}



	return 0;
}