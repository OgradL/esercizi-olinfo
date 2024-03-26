#include <iostream>
#include <vector>
using namespace std;

#define MAX 1e8

int main() {

	int N;
	cin >> N;
	int fv = MAX, fh = MAX, tv = 0, th = 0, v;
	for (int i = 0; i < N; i++){
		cin >> v;
		fh = min(fh, v);
		th += v;
	}
	for (int i = 0; i < N; i++){
		cin >> v;
		fv = min(fv, v);
		tv += v;
	}

	if (tv < th){
		cout << "Verstappen\n";
	} else {
		cout << "Hamilton\n";
	}


	if (fv < fh){
		cout << "Verstappen\n";
	} else {
		cout << "Hamilton\n";
	}

	return 0;
}