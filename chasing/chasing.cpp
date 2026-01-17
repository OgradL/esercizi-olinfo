#include <cmath>
#include <iostream>
using namespace std;

int main(){

	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	long long Dx, Dy, Ds;
	cin >> Dx >> Dy >> Ds;

	long long Bx, By, Bs;
	cin >> Bx >> By >> Bs;

	char dir;
	cin >> dir;

	long long ans;
	double t0 = 0, t1 = 0;

	if (dir == 'U' || dir == 'D'){
		long long dist = abs(Dx - Bx);

		if (dir == 'D')
			Bs = -Bs;

		t0 = dist / (double)Ds;
		By += Bs * t0;

		if (By < Dy)
			Ds = -Ds;

		t1 = (By - Dy) / (double)(Ds - Bs);

		ans = (long long)ceil(t0 + t1);
	} else {
		long long dist = abs(Dy - By);

		if (dir == 'L')
			Bs = -Bs;

		t0 = dist / (double)Ds;
		Bx += Bs * t0;

		if (Bx < Dx)
			Ds = -Ds;

		t1 = (Bx - Dx) / (double)(Ds - Bs);

		ans = (long long)ceil(t0 + t1);
	}

	if (t1 < 0){
		cout << "-1\n";
	} else {
		cout << ans << "\n";
	}

	return 0;
}
