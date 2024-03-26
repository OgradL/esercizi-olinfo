/*
 * NOTE: it is recommended to use this even if you don't
 * unde	rstand the following code.
 */

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// constraints
#define MAXN 300000

// input data
int N;
vector<int> P;

int main() {
	
	freopen("input1.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);

    cin >> N;
    P.resize(N);
    for(int i = 0; i < N; i++)
        cin >> P[i];
    
    sort(P.begin(), P.end());
	
	int totale = 0;
	int boj = 1;
	
	for (int i = N - 1; i >= 0; i--){
		if (boj % 3 != 0){
			totale += P[i];
		}
		
		//cout << boj << " " << totale << " " << P[i] << " " << boj % 3 << "\n";
		
		boj++;
	}
    
    cout << totale << endl; // print the result
    return 0;
}
