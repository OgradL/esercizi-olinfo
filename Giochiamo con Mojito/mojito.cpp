#include <bits/stdc++.h>

using namespace std;

/*bool operator <(const pair<int, int>& a, const pair& b){
	return (a.first < b.first);
}*/

struct cord{
	int x, y;
	
	cord(int t, int j){
		x = t;
		y = j;
	}
	
	cord(){
		
	}
	
};

struct person{
	
	cord pos;
	cord tir;
	bool ha_tirato = false;
	
	person(cord a, cord b){
		pos = a;
		tir = b;
		ha_tirato = false;
	}
	
	person(){
		pos = cord(0, 0);
		tir = cord(0, 0);
		ha_tirato = false;
	}
	
};

int dist(cord a, cord b){
	
	return abs(a.x - b.x) + abs(a.y - b.y);
	
}

int main(){
	
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	
	int X, Y, Mx, My, N;
	
	cin >> X >> Y >> Mx >> My >> N;
	
	Mx--;
	My--;
	
	vector<person> p(N);
	
	vector<vector<cord> > map(X, vector<cord>(Y, cord(INT_MAX, -1)));
	
	
	int A, B, C, D;
	
	for (int i = 0; i < N; i++){
		cin >> A >> B >> C >> D;
		p[i] = person(cord(A - 1, B - 1), cord(C - 1, D - 1));
	}
	
//	for (int i = 0; i < X; i++){
//		for (int j = 0; j < Y; j++){
//			cout << map[i][j].first << " " << map[i][j].second << " | ";
//		}
//		cout << "\n";
//	}
	
	for (int i = 0; i < X; i++){
		for (int j = 0; j < Y; j++){
			for (int k = 0; k < N; k++){
				if (dist(p[k].pos, cord(i, j)) < map[i][j].x){
					map[i][j].x = dist(p[k].pos, cord(i, j));
					map[i][j].y = k;
				}
			}
			//cout << map[i][j].first << " " << map[i][j].second << " - ";
		}
		//cout << "\n";
	}
	
	int ans = 0;
	
	while (true){
		
		//person o = p[map[Mx][My].second];
		//cout << "ood\n";
		bool good = p[map[Mx][My].y].ha_tirato;
		//cout << "ood\n";
		p[map[Mx][My].y].ha_tirato = true;
		Mx = p[map[Mx][My].y].tir.x;
		My = p[map[Mx][My].y].tir.y;
		//cout << "ood\n";
		
		if (good) break;
		
		ans++;
		
	}
	
	cout << ans << "\n";
	
	return 0;
}
