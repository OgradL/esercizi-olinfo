#include <vector>
#include <tuple>
using namespace std;

using ll = long long;

tuple<char, ll, ll> prisonier(ll W, vector<ll> notebook){
	if (notebook.size() == 0){
		if (W == 0)
			return {'w', -1, 0};
		return {'w', -1, -1};
	}

	if (notebook.size() >= 12 && notebook[0] == 0){
		long long ans = 1;
		for (int i = 11; i > 1; i--){
			ans += notebook[i] << (i-2);
		}
		return {'a', ans, 0};
	}

	if (notebook[0] == 0){
		return {'w', 0, W};
	} else {
		int ok = 1;
		for (int i = 1; i < notebook.size(); i++)
			ok &= notebook[i] == 0;
		if (ok)
			return {'w', W ^ 1, W ^ 1};
		else
			return {'w', W, W};
	}
}
