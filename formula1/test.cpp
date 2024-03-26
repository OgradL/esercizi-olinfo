#include <iostream>
#include <math.h>
#include <iomanip>
using namespace std;

int main(){

	cout << setprecision(26);
	double x = 1000000;
	cout << x << " " << x * x << "\n";

	cout << sqrt(x * x) << "\n";

	x += 2.0;

	cout << x << " " << x * x << "\n";

	return 0;
}