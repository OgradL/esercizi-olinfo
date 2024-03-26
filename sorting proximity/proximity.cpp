// NOTE: it is recommended to use this even if you don't understand the following code.

#include <bits/stdc++.h>
#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

typedef long long ll;

//ll proximity(int N, vector){


// input data
int N;
vector<int> V;

int main() {
	
//	ifstream cin("input.txt");
//	ofstream cout("output.txt");

    cin >> N;
    V.resize(N);
    for (int i=0; i<N; i++)
        cin >> V[i];
    
    ll a = 0;
    
    for (int i = 0; i < i + 1; i++){
    	a = max(int(a), i);
    	if (a != i){
    		break;
		}
	}
    
    
    
    cout << a << endl; // print the result
    return 0;
}
