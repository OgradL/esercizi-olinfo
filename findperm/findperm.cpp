#include <iostream>
#include <vector>
using namespace std;

int ask(int i, int j){
	cout << "? " <<  i+1 << " " << j+1 << endl;
	int ret;
	cin >> ret;
	return ret;
}

int main(){

	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int N;
	cin >> N;

	vector<int> hi_bit(N);
	vector<vector<int>> by_bit(10);
	for (int i = 0; i < N; i++){
		hi_bit[i] = ask(i, i);
		by_bit[hi_bit[i]].push_back(i);
	}

	vector<int> powers;
	vector<int> ans(N, 0);

	for (auto& arr : by_bit){
		for (int x : arr){
			int c = 0, v;
			for (int i = 0; i < powers.size(); i++){
				if ((v = ask(powers[i], x)) >= 0)
					ans[x] |= 1 << v;
				c += v != -1;
			}
			ans[x] |= 1 << hi_bit[x];
			if (!c){
				powers.push_back(x);
			}
		}
	}

	cout << "! ";
	for (int x : ans){
		cout << x << ' ';
	}
	cout << endl;


	return 0;
}
