#include <assert.h>
#include <stdio.h>
#include <string.h>
#include <cmath>
#include <iostream>

using namespace std;

// constraints
#define MAXN 1000000

typedef long long ll;

//         0  1  2  3  4  5  6  7  8  9
int X[] = {1, 0, 1, 2, 0, 1, 2, 0, 1, 2};
int Y[] = {3, 0, 0, 0, 1, 1, 1, 2, 2, 2};

int main() {
	
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);
    
    string str;
    cin >> str;
    
    ll answer = (int)str.size();
    
    for (int i = 0; i < str.size() - 1; i++){
    	//cout << int(str[i]) - 48 << " ";
    	answer += abs(X[int(str[i])-48] - X[int(str[i+1])-48]) + abs(Y[int(str[i])-48] - Y[int(str[i+1])-48]);
    	//cout << abs(X[str[i]-48] - X[str[i+1]-48]) + abs(Y[str[i]-48] - Y[str[i+1]-48]) << " ";
	}
    answer += abs(X[0] - X[int(str[0])-48]) + abs(Y[0] - Y[int(str[0])-48]);
    
    printf("%lld\n", answer);
    return 0;
}
