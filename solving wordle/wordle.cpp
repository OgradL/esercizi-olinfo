//Scrivi qui il tuo codice
// NOTE: it is recommended to use this even if you don't understand the following code.

#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

// input data
int N;
vector<char> L;

int main() {
//  uncomment the following lines if you want to read/write from files
//  ifstream cin("input.txt");
//  ofstream cout("output.txt");

    cin >> N;
    L.resize(N);
    for (int i=0; i<N; i++)
        cin >> L[i];
    
    int let = 0;
    int tra = 0;
    
    char tratt = '_';

    for (int i = 0; i < N; i++){
        if (L[i] == tratt){
            tra++;
        } else {
            let++;
        }
    }
    
    long long ans = 1;
    for (int i = 0; i < tra; i++){
        ans = ans * (26 - let - i);
    }
    
    cout << ans << endl; // print the result
    return 0;
}