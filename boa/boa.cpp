#include <iostream>
#include <vector>
using namespace std;

int main(){

	cin.tie(0);
	cin.sync_with_stdio(false);

	int N;
	cin >> N;

	vector<vector<int>> adj1(N, vector<int>(N, 0));

	for (auto &v : adj1)
		for (auto &n : v) 
			cin >> n;


	for (auto &v : adj1){
		for (auto &n : v){
			
		}
	}


	return 0;
}