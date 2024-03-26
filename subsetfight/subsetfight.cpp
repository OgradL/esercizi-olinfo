#include <iostream>
#include <vector>
using namespace std;

int main(){

	int N;
	cin >> N;

	vector<int> V(N);
	for (int &n : V)
		cin >> n;
	
	vector<vector<int>> dp(N, vector<int>(N, 0));

	for (int i = 0; i < N; i++){
		for (int j = 0; j < N; j++){
			
		}
	}




	return 0;
}