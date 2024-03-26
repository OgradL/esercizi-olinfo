#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <math.h>
using namespace std;

struct event{
	int type;
	double t;
	int p = 0, c1 = 0, c2 = 0;
	event(int ty, double ti, int pi): t(ti), type(ty), p(pi) {}
	event(int ty, double ti, int c1_, int c2_): t(ti), type(ty), c1(c1_), c2(c2_) {}
};

int main(){

	cin.tie(0);
	cin.sync_with_stdio(false);
	cout.tie(0);
	cout.sync_with_stdio(false);

	int N;
	cin >> N;

	vector<int> A(N), B(N), C(N);
	for(int i = 0; i < N; i++){
		cin >> A[i] >> B[i] >> C[i];
	}

	vector<event> events;
	double na, nb, nc;
	for (int i = 0; i < N; i++){
		for (int j = i+1; j < N; j++){
			na = A[i] - A[j];
			nb = B[i] - B[j];
			nc = C[i] - C[j];


			if (abs(na) > 0.000001){
				double delta = sqrt(nb * nb - 4 * na * nc);
				double vert = -nb / (2*na);

				double x1 = (-nb + delta) / (2 * na);
				double x2 = (-nb - delta) / (2 * na);

				double d1 = 2*A[i]*x1 + B[i];
				double d2 = 2*A[j]*x1 + B[j];

				int c1 = (d1 > d2)?(i):(j);
				int c2 = (d1 > d2)?(j):(i);

				if (x1 >= 0)
					events.push_back(event(1, x1 + 0.0000001 * (c1 > c2), c1, c2));
				if (x2 >= 0)
					events.push_back(event(1, x2 + 0.0000001 * (c2 > c1), c2, c1));
			} else if (abs(nb) > 0.000001){
				double x = -nc / nb;
				
				double d1 = 2*A[i]*x + B[i];
				double d2 = 2*A[j]*x + B[j];

				int c1 = (d1 > d2)?(i):(j);
				int c2 = (d1 > d2)?(j):(i);

				if (x >= 0)
					events.push_back(event(1, x + 0.0000001 * (c1 > c2), c1, c2));
			} else {
				// nothing yay
			}
		}
	}


	int Q;
	cin >> Q;
	vector<event> queries(Q, event(2, 0, 0));
	for (int t = 0; t < Q; t++){
		cin >> queries[t].p >> queries[t].t;
		queries[t].c1 = queries[t].c2 = t;
		queries[t].type = 2;
	}

	events.insert(events.end(), queries.begin(), queries.end());

	sort(events.begin(), events.end(), [&](event& a, event& b){
		if (a.t != b.t) return a.t < b.t;
		return a.type < b.type;
	});
	
	
	vector<int> cla(N), pos(N);
	for (int i = 0; i < N; i++){
		cla[i] = i;
	}
	sort(cla.begin(), cla.end(), [&C](int a, int b){
		return C[a] > C[b];
	});
	for (int i = 0; i < N; i++){
		pos[cla[i]] = i;
	}
	

	
	vector<int> ans(Q);
	vector<vector<int>> done(N, vector<int>(N, 0));

	for (event e : events){
		if (e.type == 1){

			//*
			if (pos[e.c1] > pos[e.c2]){
				swap(cla[pos[e.c1]], cla[pos[e.c2]]);
				swap(pos[e.c1], pos[e.c2]);
			}
			//*/

			// if (done[e.c1][e.c2])
			// 	continue;
			
			// int c3 = cla[pos[e.c1]-1];
			// swap(cla[pos[e.c1]], cla[pos[c3]]);
			// pos[c3]++;
			// pos[e.c1]--;
			// done[e.c1][c3] = done[c3][e.c1] = 1;

			// if (c3 != e.c2){
			// 	int c4 = cla[pos[e.c2]+1];
			// 	swap(cla[pos[e.c2]], cla[pos[c4]]);
			// 	pos[c4]--;
			// 	pos[e.c2]++;
			// 	done[e.c2][c4] = done[c4][e.c2] = 1;
			// }
			// cout << e.type << " " << e.t << " " << e.c1 << " " << e.c2 << "\n";
		} else {
			int c = cla[e.p-1] + 1;
			ans[e.c1] = c;
			// cout << e.type << " " << e.t << " " << e.p << "\n";
		}
		// cout << "classifica:\n";
		// for (int i = 0; i < N; i++){
		// 	cout << cla[i] << " ";
		// }
		// cout << "\n";
	}

	for (int i = 0; i < Q; i++){
		cout << ans[i] << "\n";
	}

	return 0;
}