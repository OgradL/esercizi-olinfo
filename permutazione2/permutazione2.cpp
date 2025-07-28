#include <algorithm>
#include <cmath>
#include <vector>
#include <stdbool.h>
using namespace std;

bool chiedi(int K);
void stato();
void sposta();

struct group {
	int l, r;
	vector<int> vals;
};

void solve6(int N, int A, int B, int C, int H[]){
	vector<group> groups;

	vector<int> v;
	for (int i = 0; i < N; i++){
		v.push_back(i);
	}

	groups.push_back({0, N, v});

	int dir = 0, actual_dir = 0;
	int x = 0;

	auto go_to = [&](int pos){
		if (pos == x)
			return;
		if (pos < x != actual_dir){
			actual_dir = 1 - actual_dir;
			stato();
		}
		while (x != pos){
			sposta();
			x -= actual_dir * 2 - 1;
		}
	};

	while (!groups.empty()){
		vector<group> new_groups;

		for (auto [l, r, vals] : groups){

			if (r - l == 1){
				H[l] = vals[0];
				continue;
			}

			int mid = (l + r) / 2;
			go_to(mid - 1);

			group lo{l, mid, {}};
			group hi{mid, r, {}};

			for (int x : vals){
				if (chiedi(x)){
					lo.vals.push_back(x);
				} else {
					hi.vals.push_back(x);
				}
			}

			if (dir == 0){
				new_groups.push_back(lo);
				new_groups.push_back(hi);
			} else {
				new_groups.push_back(hi);
				new_groups.push_back(lo);
			}
		}

		dir = 1 - dir;
		reverse(new_groups.begin(), new_groups.end());
		groups = new_groups;
	}
}

void solve7(int N, int A, int B, int C, int H[]){
	vector<vector<int>> groups;
	
	int sz = sqrt(N);
	
	int x = 0;

	vector<int> seen(N, 0);
	int i;
	for (i = 0; i * sz < N; i++){
		while (x+1 < min(N, (i+1)*sz)){
			x++;
			sposta();
		}

		groups.push_back({});
		for (int j = 0; j < N; j++){
			if (seen[j])
				continue;

			if (chiedi(j)){
				seen[j] = 1;
				
				groups.back().push_back(j);
			}
		}
	}

	stato();

	seen.assign(N, 0);

	for (i--; i >= 0; i--){
		while (x >= i*sz){
			if (groups[i].size() == 1){
				H[x] = groups[i][0];
				groups[i].clear();
			}
			if (x > 0)
				sposta();
			x--;
			for (int j : groups[i]){
				if (!chiedi(j)){
					H[x+1] = j;
					groups[i].erase(find(groups[i].begin(), groups[i].end(), j));
					break;
				}
			}
		}
	}
}

void indovina(int N, int A, int B, int C, int H[]) {
	if (B == 1){
		solve7(N, A, B, C, H);
	} else {
		solve6(N, A, B, C, H);
	}
}
