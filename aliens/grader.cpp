#include <iostream>
#include <vector>
using namespace std;

vector<vector<int>> map;

int XC, YC;
bool examine(int X, int Y){
	if (X < 1 || Y < 1) return false;
	if (X > map.size() || Y > map[0].size()) return false;
	return map[X][Y];
}

void solution(int Xc, int Yc){
	int ok = Xc == XC && Yc == YC;

	if (ok){
		cout << "Correct: " << Xc << " " << Yc << "\n";
	} else {
		cout << "Wrong: " << Xc << " " << Yc << " instead of " << XC << " " << YC << "\n";
	}
}

void find_centre(int N, int Xi, int Yi);

int main(){

	cin >> XC >> YC;
	int sz = 3;
	cin >> sz;

	map.assign(100, vector<int>(100, 0));

	int x = XC - sz/2 - 2*sz;
	int y = YC - sz/2 - 2*sz;


	for (int i = 0; i < 5; i++){
		for (int j = 0; j < 5; j++){
			if ((i + j) % 2) continue;

			for (int i0 = 0; i0 < sz; i0++){
				for (int i1 = 0; i1 < sz; i1++){
					map[x + sz*i + i0][y + sz*j + i1] = 1;
				}
			}
		}
	}

	for (int i = 0; i < 50; i++){
		for (int j = 0; j < 50; j++){
			cout << map[j][i] << ' ';
		}
		cout << "\n";
	}
	cout << x << " " << y << "\n";
	cout << "\n\n";

	find_centre(100, x, y);

	return 0;
}
