#include <iostream>
using namespace std;

int main(){

	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int Sa, Ta, Ua;
	cin >> Sa >> Ta >> Ua;

	int Sb, Tb, Ub;
	cin >> Sb >> Tb >> Ub;

	cout << abs(Sa - Sb) + abs(Ta - Tb) + abs(Ua - Ub) << "\n";

	return 0;
}
