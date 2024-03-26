//Scrivi qui il tuo codice
// NOTE: it is recommended to use this even if you don't understand the following code.
//#pragma GCC optimize ("Ofast") 
//#pragma GCC optimization ("unroll-loops")
#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

// input data
int N;
vector<int> V, S;

int main() {
	
	//ifstream cin("input.txt");
	//ofstream cout("output.txt");

    cin >> N;
    V.resize(N);
    S.resize(N);
    for (int i=0; i<N; i++)
        cin >> V[i];
    for (int i=0; i<N; i++)
        cin >> S[i];
	
	int previous = 0;
	int current = 0;
	int total = 0;
	int maxo = 0;
	
	for (int i = 0; i < N; i++){
		
		if (S[i] == 0){
			total = 0;
			continue;
		} else {
			current = V[i];
			if (current > previous){
				total += current;
				maxo = max(total, maxo);
			} else {
				total = 0;
			}
			
			
		}
		
		previous = V[i];
		
	}
	
	
	
    cout << maxo << endl; // print the result
    return 0;
}
