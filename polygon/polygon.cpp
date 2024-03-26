#include <iostream>
using namespace std;

int gcd(int a, int b){
	return (b <= 0) ? a : gcd(b, a % b);
}

int main(){
	
	int N;
	cin >> N;
	
	int x1, x2, y1, y2, area = 0, xs, ys;
	cin >> xs >> ys;
	x1 = xs;
	y1 = ys;
	double rem = 0;
	for (int i = 1; i < N; i++){
		cin >> x2 >> y2;
		area += (x1*y2 - x2*y1);
		rem += (gcd(abs(x2-x1), abs(y2-y1)));
		x1 = x2;
		y1 = y2;
	}
	
	area += (x1*ys-xs*y1);
	
	cout << abs(area) / 2 << "\n";
	
	return 0;
}