#include <iostream>

using namespace std;

int main() {
	
	freopen("input1.txt", "r", stdin);
	//freopen("output0.txt", "w", stdout);
    int N;
    cin >> N;
	
	long long o = 0;
	long long v = 0;
	
	if (N % 2 == 0){
		o = int(N / 2);
		v = int(N / 2);
	} else {
		v = int(N / 2) + 1;
		o = int(N / 2);
	}
	
	long long total = (o + 1) * (v + 1);
	
    cout << total << endl;
    return 0;
}
