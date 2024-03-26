/*
 * NOTE: it is recommended to use this even if you don't
 * understand the following code.
 */

#include <iostream>

using namespace std;

// input data
int N, M, E;

int main() {
	
	freopen("input1.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);

    cin >> N >> M >> E;
	
	int current = 0;
	
	for (int i = M; i <= N; i++){
		current = max(current, E % i);
	}
	
    cout << current << endl; // print the result
    return 0;
}
