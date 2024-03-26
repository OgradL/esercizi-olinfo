#include <iostream>
#include <vector>
using namespace std;


int main() {

	int N;
	
	cin >> N;
	
	string S;
	char c;
	for (int i = 0; i < N; i++){
		cin >> c;
		if (c != S.back())
			S.push_back(c);
	}

	N = S.size();
	int ans = 0;

	int idx = 0;
	while (true){
	
	}
	
	cout << ans << endl;
	
	return 0;
}
