#include <iostream>
#include <string.h>
using namespace std;

int main(){

	int N;
	cin >> N;

	int map[210][210];
	memset(map, 0, 210*210);

	int ans = 0;
	int x1, y1, x2, y2;
	while (N--){
		cin >> x1 >> y1 >> x2 >> y2;
		if (x1 > x2)
			swap(x1, x2);
		if (y1 > y2)
			swap(y1, y2);
		for (int i = x1; i < x2; i++)
			for (int j = y1; j < y2; j++){
				ans = max(ans, ++map[i+103][j+103]);
			}

	}

	cout << ans << "\n";

	return 0;
}