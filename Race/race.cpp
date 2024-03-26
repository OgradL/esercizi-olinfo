#include <iostream>
#include <vector>
#include <algorithm>
#include <tuple>
using namespace std;


int time = 1;

int calc(int a, int b){
	return a + b * (time - 1);
}

int main(){

	int N;
	cin >> N;

	int a, b;
	vector<tuple<int, int, int>> C(N);
	for (int i = 0; i < N; i++){
		cin >> get<0>(C[i]) >> get<1>(C[i]);
		get<2>(C[i]) = i;
	}
	int size = C.size();
	for (; size > 1;){
		for (int i = 0; i < size; i++) cout << get<2>(C[i]) << " ";
		cout << "\n";
		sort(C.begin(), C.begin() + size * sizeof(C[0]), [](const tuple<int, int, int>& a, const tuple<int, int, int>& b){
			return 
				calc(get<0>(a), get<1>(a)) <
				calc(get<0>(b), get<1>(b));
		});
		time++;
		size /= 2;
	}

	cout << get<2>(C[0]) << "\n";

	return 0;
}