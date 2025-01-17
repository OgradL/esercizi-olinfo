#include <iostream>
#include <assert.h>
using namespace std;

int main(){

	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	string A, B;
	cin >> A >> B;

	int prefix = 0;
	for (int i = 0; i < A.size() && i < B.size(); i++){
		if (A[i] != B[i])
			break;
		prefix++;
	}

	if (A.size() == prefix){
		if (B.size() >= prefix + 2){
			cout << B.substr(0, prefix+1) << "\n";
		} else {
			cout << "-1\n";
		}
		return 0;
	}

	if (A[prefix] + 1 < B[prefix]){
		cout << A.substr(0, prefix) + (char)(A[prefix] + 1) << "\n";
		return 0;
	}

	if (B.size() > prefix + 1){
		cout << B.substr(0, prefix+1) << "\n";
		return 0;
	}

	int i = prefix+1;
	for (; i < A.size(); i++){
		if (A[i] != 'z')
			break;
	}

	cout << A.substr(0, i) + 'z' << "\n";

	return 0;
}
