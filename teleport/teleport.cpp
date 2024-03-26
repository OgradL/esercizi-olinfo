#include <iostream>
#include <string>
#include <vector>
#include <queue>
using namespace std;

#define INF 1e9
#define mp(a, b) make_pair((a), (b))

pair<int, int> bfs(int x, int y, char startchar, char otherchar, vector<string>& map){

	queue<pair<pair<int, int>, int>> q;
	
	int H = map.size();
	int W = map[0].size();

	vector<vector<int>> v(H, vector<int>(W, 0));

	q.push({{x, y}, 0});

	int px, py;
	int c;
	pair<pair<int, int>, int> t1;
	pair<int, int> t2;
	int closest_pass = INF, other_house = INF;
	while (!q.empty()){
		t1 = q.front();
		t2 = t1.first;
		c = t1.second;
		px = t2.first;
		py = t2.second;
		q.pop();


		if (py < 0 || py >= H)
			continue;
		if (px < 0 || px >= W)
			continue;
		
		if (v[py][px])
			continue;
		v[py][px] = 1;

		if (map[py][px] == '#'){
			continue;
		}
		if (map[py][px] == '@'){
			closest_pass = min(closest_pass, c);
		}
		if (map[py][px] == otherchar){
			other_house = c;
		}
		
		q.push(mp(mp(px + 1, py), c + 1));
		q.push(mp(mp(px - 1, py), c + 1));
		q.push(mp(mp(px, py + 1), c + 1));
		q.push(mp(mp(px, py - 1), c + 1));
	}
	
	return mp(closest_pass, other_house);
}

int main(){

	cin.tie(0);
	cin.sync_with_stdio(false);

	int H, W;
	cin >> H >> W;

	vector<string> map(H);
	for (string &s : map) cin >> s;

	int Cx, Cy, Mx, My;

	for (int i = 0; i < H; i++){
		for (int j = 0; j < W; j++){
			if (map[i][j] == 'C'){
				Cx = j;
				Cy = i;
			}
			if (map[i][j] == 'M'){
				Mx = j;
				My = i;
			}
		}
	}

	pair<int, int> a = mp(INF, INF), b = mp(INF, INF);
	a = bfs(Cx, Cy, 'C', 'M', map);
	if (a.second > a.first)
		b = bfs(Mx, My, 'M', 'C', map);

	int ans = min(a.first + b.first + 1, a.second);

	cout << ans << "\n";

	return 0;
}